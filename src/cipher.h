#ifndef _CIPHER_H_
#define _CIPHER_H_

#include <stdio.h> 
#include <string.h>
#include <assert.h>

#include "definitions.h"
#include "cipher_utils.h"

// Prototypes ::
void ceasar_encrypt (char * to_encrypt);
void ceasar_decrypt (char * to_decrypt);
void vegenere_crypt (char * message, char * key);
void vegenere_decrypt (char * message, char * key);

char * encrypt (char * message);
char * decrypt (char * message);

void
ceasar_encrypt (char * to_encrypt) {
    assert (to_encrypt != NULL);

	int i;

  	for (i = 0; i < strlen (to_encrypt); i++) {

	  	to_encrypt [i] = to_encrypt [i] + 1;

	}
}

void
ceasar_decrypt (char * to_decrypt) {
  	assert (to_decrypt != NULL);

	int i;

  	for (i = 0; i < strlen (to_decrypt); i++) {
		to_decrypt [i] = to_decrypt [i] - 1;
	}
}

char * 
encrypt (char * message) {
  	assert (message != NULL);

    int i;
    char bin[8];
	char * encrypted = NEW (char, ((strlen (message)*8)+1));

  	ceasar_encrypt (message);

    for (i = 0; i < ((int) strlen (message)); i++) {
        char_to_bin (bin, message [i]);
        strcat (encrypted, bin);
    }

    encrypted [strlen (encrypted)] = 0x00;

    for (i = 0; i < ((int) strlen (encrypted)); i++) {
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

    char bin [8];
    int i;
    int j = 0;
    int k = 0;
    char * decrypted = NEW (char, strlen (message)/8);

    for (i = 0; i < (int) strlen (message); i++) {
        
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

  	ceasar_decrypt (decrypted);

    return decrypted;
}

void 
vigenere_crypt (char * message, char * key) {
  	assert ((message != NULL) && (key != NULL));

    int i = 0;
    int cn = 0;
    
    for (i = 0; i <= strlen(message); i++) {
        if (i > 0) {
            message[(i - 1)] = cn;
        }
        cn =  ((int)message[i]) + ((int)key[i]);
        while (cn > 126) {
            cn = 32 + (cn % 126);
        }
    }
}

void
vigenere_decrypt (char * message, char * key) {
    assert ((message != NULL) && (key != NULL));

    int i = 0;
    int cn = 0;

    for (i = 0; i <= strlen (message); i++) {
        if (i > 0) {
            message [(i - 1)] = cn;
        }
        cn = ((int)message[i] - ((int)key[i]));
        while (cn < 32) {
            cn = 126 - (32 - cn);
        }
    }
}

#endif /* _CIPHER_H_*/

