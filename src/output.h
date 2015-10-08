#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "color_set.h"
#include "definitions.h"

void splash (void);
void help (void);
void usage (const char * itself);

bool toFile (const char * filepath, const char * binMsg);
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
            "  -h, --help\t\tShows this help message.\n\n" \
            "  -e <message> <filename>\t\tEncrypts the message to setted file\n" \
            "  -d <filepath>\t\tDecryps the message\n%s",
            T_GREEN, SW_NAME, NOTHING);

}

void
usage (const char * itself) {
   printf ("Usage: %s <message>\n", itself);
   exit (-11);
}


bool
toFile (const char * filepath, const char * binMsg) {
    
    FILE * fp = fopen (filepath, "a");
    if (fp == NULL) {
        printf ("Error writing encrypted message to te file: %s\n", filepath);
        return false;
    }


    return ((fprintf (fp, "%s", binMsg) == (int) strlen (binMsg)) 
            ? true 
            : false);   
}

#endif /* _OUTPUT_H_ */

