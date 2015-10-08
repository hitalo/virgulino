#ifndef _CYPHER_H_
#define _CYPHER_H_

#include <stdio.h>  // for debugging reasons
#include <string.h>
#include <assert.h>

#include "definitions.h"

void char_to_bin (char * bin, char c);
char bin_to_char (char * bin);

char * translate (const char * filepath);

char * encrypt (char * message);
char * decrypt (char * message);


// I choose this convention style for
// function declarations, if you, guys, don't 
// like it, please, let me know.
void
char_to_bin (char * bin, char c) {
    int i;

    for (i = 0; i < 8; ++i) {
            bin[i] = ((!!((c << i) & 0x80))+'0');
    }

}

char 
bin_to_char (char * bin) {
    char c = 0x00;

    for (int i = 0; i < 8; i++) {
        if (bin [i] == '1') {
            c |= 1 << (7 - i);       
        }
    }   
    return c;
}

char * 
translate (const char * filepath) {
    assert (filepath != NULL);

    FILE * fp = NULL;
    long int file_size = 0;    
    char * content = NULL;

    int i = 0;

    fp = fopen (filepath, "r");
    if (fp == NULL) {
        printf ("Error opening the file [!!]\n");
        exit (-1);
    }

    fseek (fp, 0L, SEEK_END);
    file_size = ftell (fp);
    rewind (fp);

    content = NEW (char, file_size);


    for (i = 0; i < (file_size); i++) {

        (fgetc (fp) == 0x09) ? (content [i] = '1') : (content [i] = '0');

    }
    
    //printf ("\n\tDEBUG: %s\n", content); 


    return content;

}

char * 
encrypt (char * message) {
    assert (message != NULL);

    char bin[8];


    char * encrypted = NEW (char, ((strlen (message)*8)+1));


    for (int i = 0; i < ((int) strlen (message)); i++) {
        char_to_bin (bin, message [i]);
        strcat (encrypted, bin);
    }

    encrypted [strlen (encrypted)+1] = 0x00;

    for (int i = 0; i < ((int) strlen (encrypted)); i++) {
        if (encrypted [i] == '1') {
            encrypted [i] = 0x09;
        } else {
            encrypted [i] = 0x20;
        } 
    }

    return encrypted;
}


// todo
char *
decrypt (char * message) {
    assert (message != NULL);

    char * decrypted = NEW (char, strlen (message)/8);
    char bin [8];

    int j = 0;
    int k = 0;
    for (int i = 0; i < (int) strlen (message); i++) {
        
        bin [j] = message [i];
        if (j == 7) {
            decrypted [k] = bin_to_char (bin);
            k++;
            j = 0;
            continue;
        } 
        j++;

    }
    free (message);

    return decrypted;
}




#endif /* _CYPHER_H_*/
