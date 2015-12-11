// PoC Vigenere cypher [!!]

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt (char * msg, char * key);
void decrypt (char * msg, char * key);

int main(int argc, char ** argv) {
    
    char str[32];
    
    if (argc < 3) {
        printf ("key is missing [!!]\n");
        exit(1);
    }


    if (strlen(argv[1]) == strlen(argv[2])) {
        printf ("Before: %s\n", argv[1]);
        encrypt (argv[1], argv[2]);
    } else {
        printf ("diffente length\n");
        exit (1);
    }
    

    printf ("encrypted: %s\n", argv[1]);
    decrypt (argv[1], argv[2]);
    printf ("decrypted: %s\n", argv[1]);
    return 0;
}

void
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

}

void
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


}
