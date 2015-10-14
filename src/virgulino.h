#ifndef _VIRGULINO_H_
#define _VIRGULINO_H_

#include "definitions.h"
#include "output.h"
#include "color_set.h"
#include "cypher.h"

#include <ctype.h>
#include <unistd.h>
#include <getopt.h>

void handler (char argc, char ** argv);


static void 
debug (int i) {
    printf ("[DEBUG] %d\n", i);
}

//static int verbose_flag;


void
handler (char argc, char ** argv) {
   char * enc = NULL;
   char * dec = NULL;

   char * e_value = NULL;
   char * filepath = NULL;

   unsigned char d_flag = 0;
   unsigned char f_flag = 0;
   int c = -10;

   if (argc == 1) {
       usage (argv[0]);
   }
   while (1) {
       static struct option long_options [] =  {
           {"encypt",   required_argument,      0, 'e'},
           {"decrypt",  no_argument,            0, 'd'},
           {"file",     required_argument,      0, 'f'},
           {"help",     no_argument,            0, 'h'},
           {0,          0,                      0,  0}
       };
       int option_index = 0;

       c = getopt_long (argc, argv, "e:df:h", 
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

               e_value = optarg;
               enc = encrypt (e_value);
               break;

           } case 'd': {

               d_flag = 1;

               break;

           } case 'f': {
               f_flag = 1;
               filepath = optarg;
               if (d_flag == 1) {
                    
                    dec = decrypt (translate (filepath));
                    printf ("%s\n", dec);
                    free (dec);

               } else if (enc != NULL) {
                    if (to_file (filepath, enc) == false) {
                        err_msg ("writing to file");
                        free (enc);
                        exit (1);
                    }
                    free (enc);

               }
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

   /*  
   if (verbose_flag) {
       printf ("bla\n");
   }
   */
   if (optind < argc) {
       printf ("non-option argv-elements: ");
       while (optind < argc) {
           printf ("%s ", argv[optind ++]);
       }
       putchar ('\n');
   }

   if (d_flag == 1 && f_flag == 0) {
        printf ("[%sWARN%s] - Filepath not setted\n"\
                "use: -f <filepath>\n", 
                T_YELL, NOTHING);
        exit (1);
   }

   if (e_value != NULL && f_flag == 0) {
       printf ("%s", enc);
       free (enc);
   }
}

#endif /* _VIRGULINO_H_ */

