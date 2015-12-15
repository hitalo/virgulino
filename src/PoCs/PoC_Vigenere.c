// PoC Vigenere cypher [!!]
#include "definitions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

BOOL encrypt (char * msg, char * key);
BOOL decrypt (char * msg, char * key);
BOOL verify (const char * msg);

int main(int argc, char ** argv) {
    
    char str[32];
    
    if (argc < 3) {
        printf ("key is missing [!!]\n");
        exit(1);
    }


    if (strlen(argv[1]) == strlen(argv[2])) {
        printf ("Before: %s\n", argv[1]);
        if (!encrypt (argv[1], argv[2])) {
            error ("in encrypt");
            exit(1);
        }
    } else {
        printf ("diffente length\n");
        exit (1);
    }
    

    printf ("encrypted: %s\n", argv[1]);
    if (!decrypt (argv[1], argv[2])) {
        error ("in decrypt()");
        exit(1);
    }
    printf ("decrypted: %s\n", argv[1]);
    return 0;
}

BOOL
encrypt (char * msg, char * key) {
    int i = 0;
    int cn = 0;
    
    for (i = 0; i <= strlen(msg); i++) {
        if (i > 0) {
            msg[(i - 1)] = cn;
        }
        cn =  ((int)msg[i]) + ((int)key[i]);
        while (cn > 126) {
            cn = 32 + (cn % 126);
        }
    }
    return TRUE;

}

BOOL
decrypt (char * msg, char * key) {
    int i = 0;
    int cn = 0;

    for (i = 0; i <= strlen (msg); i++) {
        if (i > 0) {
            msg [(i - 1)] = cn;
        }
        cn = ((int)msg[i] - ((int)key[i]));
        while (cn < 32) {
            cn = 126 - (32 - cn);
        }
    }
    return TRUE;
}

BOOL 
verify (const char * str) {
    int i;
    for (i = 0;i < str; i++) {
        if (str[i] < 0) {
            errorn = MIS_CHARSET;
            return FALSE;
        }
    }
}
