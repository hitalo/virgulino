#ifndef _VIRGULINO_H_
#define _VIRGULINO_H_

#include "definitions.h"
#include "output.h"
#include "color_set.h"
#include "cypher.h"
#include "hide.h"

#include <string.h>

#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>

// prototypes ::
void handler (char argc, char ** argv);
void verify_params (MessagePack * pack);
void engine (MessagePack * pack);

//functions ::
void
handler (char argc, char ** argv) {

   MessagePack pack;
   init_message_pack (&pack);

   int c = 0;

   if (argc == 1) {
       usage (argv[0]);
       exit (0);
   }
   while (1) {
       static struct option long_options [] =  {
           {"encypt",   no_argument,            0, 'e'},
           {"file",     required_argument,      0, 'f'},
           {"message",  required_argument,      0, 'm'},
           {"ceasar",   optional_argument,      0, 'c'},
           {"vigenere", optional_argument,      0, 'v'},
           {"stealthy", optional_argument,      0, 's'},
           {"randomic", no_argument,            0, 'r'},
           {"decrypt",  no_argument,            0, 'd'},
           {"help",     no_argument,            0, 'h'},
           {0,          0,                      0,  0}
       };
       int option_index;

       c = getopt_long (argc, argv, "ef:m:c::v::s::rdh", 
                        long_options, &option_index);

       if (c == -1) 
           break;

       switch (c) {
           case 0: {
                if (long_options[option_index].flag != 0)
                    break;

                printf ("option %s", long_options [option_index].name);

                if (optarg)
                    printf ("with arg %s\n", optarg);
                break;

           } case 'e': {
               pack.encode = true;
               break;
            
           } case 'f': {
               pack.filepath = optarg;
               break;

           } case 'd': {
               pack.encode = false;
               break;

           } case 'm': {
               pack.message = strdup (optarg);
               pack.message_len = strlen (optarg);
               break;

           } case 'c': {
               pack.encode_type.ceasar = true;
               pack.salt = ((!optarg && NULL != argv[optind] && '-' != argv[optind][0])
                            ? atoi (argv[optind++])
                            : DEFAULT_SALT);
               break;

           } case 'v': {
               pack.encode_type.vigenere = true;  
               pack.key = ((!optarg && NULL != argv[optind] && '-' != argv[optind][0])
                           ? strdup (argv[optind++]) 
                           : NULL);
               break;

           } case 's': {
                char * hidden_type = ((!optarg && NULL != argv[optind] && '-' != argv[optind][0])
                                      ? strdup (argv[optind++]) 
                                      : NULL);
                if (hidden_type == NULL)
                    pack.hide_type = NONE;

                if (!(strcmp (hidden_type, "txt")))
                    pack.hide_type = ASCII;

                free (hidden_type);               

                break;

           } case '?': {
               help ();
               break;

           } case 'h': {
               help ();
               break;

           } default: {
               usage (argv[0]);
               abort ();

               break;

           }
       }
   }
   
   if (optind < argc) {
       printf ("non-option argv-elements: ");
       while (optind < argc) {
           printf ("%s ", argv[optind ++]);
       }
       putchar ('\n');
       usage(SW_NAME);
       exit(1);
   }

   engine (&pack);
}

void
verify_params (MessagePack * pack) {
    bool right = true;

    if (pack->encode && !pack->message) {
        err_msg ("Message not provided");
        right = false;
    }

    if (pack->encode_type.vigenere && pack->message && !pack->key) {
        pack->key = new_random_key (pack->message);
        save_key (pack->key);
        
    }

    if (!pack->encode && !pack->filepath) {
        err_msg ("Pathfile not provided");
        right = false;
    } 

    if (!right)
        exit(1);

}


void 
engine (MessagePack * pack) {
    assert (pack);

    verify_params (pack);

    if (pack->encode) {
        encrypt (pack);
 
        switch (pack->hide_type) {
            case ASCII: {
                char * aux_hidden = hide (pack->message);
                to_file (pack->filepath, aux_hidden);
                free (aux_hidden);

                if (pack->encode_type.vigenere)
                   free (pack->key);
                free (pack->message);

                break;

            } case NONE: {
                printf ("\n\t## BEGIN MESSAGE ##\n%s\n\t ## END MESSAGE ##\n", pack->message);
                break;
            }
        }

    } else {

        switch (pack->hide_type) {
            case ASCII: {
                pack->message = unhide (pack->filepath);
                pack->message_len = strlen (pack->message);
                break;

            } case NONE: {
                break;
            }
        }
        decrypt (pack);
        printf ("\n\t## BEGIN MESSAGE ##\n%s\n\t ## END MESSAGE ##\n", pack->message);
        if (pack->encode_type.vigenere)
            free (pack->key);
        free (pack->message);

    }
}


#endif /* _VIRGULINO_H_ */

