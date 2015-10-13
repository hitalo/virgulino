#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "color_set.h"
#include "definitions.h"


// prototypes ::
void err_msg (const char * err);

void splash (void);
void help (void);
void usage (const char * itself);

bool to_file (const char * filepath, char * binmsg);



// functions ::
void
err_msg (const char * err) {
    char msg[100] = "[ERROR] - ";
    strncat (msg, err, 100-strlen(msg));

    fprintf (stderr, "%s\n", msg);
}
void 
splash (void) {
    printf ("%s"\
            "******************************************************\n"\
            "*         __                    __ __                *\n"\
            "* .--.--.|__|.----.-----.--.--.|  |__|.-----.-----.  *\n"\
            "* |  |  ||  ||   _|  _  |  |  ||  |  ||     |  _  |  *\n"\
            "*  \\___/ |__||__| |___  |_____||__|__||__|__|_____|  *\n"\
            "*                 |_____|                            *\n"\
            "*                                                    *\n"\
            "* Virgulino v0.1                                     *\n"\
            "* coded by:                                          *\n"\
            "*      n3k00n3   -   nekoone (at) riseup(dot)net     *\n"\
            "*      UserX     -   user_x(at)riseup(dot_net        *\n"\
            "*      Cascudo                                       *\n"\
            "*      gjuniioor -   gjuniioor@protonmail.ch         *\n"\
            "* LampiaoSEC - Security Research Group               *\n"\
            "* #lampiaosec at freenode                            *\n"\
            "* https://lampiaosec.github.io                       *\n"\
            "*                                                    *\n"\
            "******************************************************\n\n%s", 
            T_GREEN, T_NULL);

}


void
help (void) {
    printf ("%s./%s [OPTIONS]\n\n" \
            "OPTIONS:\n" \
            "  -h, --help\t\t\tShows this help message.\n\n" \
            "  -e \"message\" -f <filename>\tEncrypts the message to setted file\n" \
            "  -d <filepath>\t\t\tDecryps the message\n" \
            "  -f <filepath>\t\t\tfile to be used\n%s",
            T_GREEN, SW_NAME, NOTHING);

}

void
usage (const char * itself) {
   printf ("Usage: %s [-e -d -h] <message> [-f] <filepath>\n", itself);
   exit (1);
}


bool
to_file (const char * filepath, char * binMsg) {
    
    FILE * fp = fopen (filepath, "w");
    size_t written = 0;
    if (fp == NULL) {
        printf ("Error writing encrypted message to te file: %s\n", filepath);
        return false;
    }

    written = fprintf (fp, "%s", binMsg);
    if (written < strlen (binMsg)) {
        err_msg ("writing to file");   
    }
    return true;
}

#endif /* _OUTPUT_H_ */

