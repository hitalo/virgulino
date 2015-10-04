#ifndef _CYPHER_H_
#define _CYPHER_H_

#include <stdio.h>  // for debugging reasons
#include <string.h>

#include "definitions.h"

void char_to_bin (char * bin, char c);

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

char * 
encrypt (char * message) {
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
// TODO ::




#endif /* _CYPHER_H_*/
