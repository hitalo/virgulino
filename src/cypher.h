#ifndef _CYPHER_H_
#define _CYPHER_H_

#include <stdio.h> 
#include <string.h>
#include <assert.h>

#include "definitions.h"

// Prototypes ::
void char_to_bin (char * bin, char c);

void ceasar_encrypt (char * to_encrypt);
void ceasar_decrypt (char * to_decrypt);

char bin_to_char (char * bin);

char * translate (const char * filepath);

char * encrypt (char * message);
char * decrypt (char * message);



// Functions ::
void
char_to_bin (char * bin, char c) {
    int i,j;
    
    for (j = 0, i = 7; i >= 0; i--, j++) {
        bin [j] = ((c & (1 << i)) ? '1' : '0');
    }
    bin[8] = 0x00;
}

char 
bin_to_char (char * bin) {
    char c = 0x00;
    int i;
    for (i = 0; i < 8; i++) {
        if (bin [i] == '1') {
            c |= 1 << (7 - i);       
        }
    }
    return c;
}

void
ceasar_encrypt (char * to_encrypt) {
	int i;
  	for (i = 0; i < strlen (to_encrypt); i++) {

	  	to_encrypt [i] = to_encrypt [i] + 1;

	}
}

void
ceasar_decrypt (char * to_decrypt) {
	int i;
  	for (i = 0; i < strlen (to_decrypt); i++) {
		to_decrypt [i] = to_decrypt [i] - 1;
	}
}

char *
translate (const char * filepath) {
    int i;

    assert (filepath != NULL);

    FILE * fp = NULL;
    long int file_size = 0;    
    char * content = NULL;

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
    
   
    return content;

}

char * 
encrypt (char * message) {
    int i;

    assert (message != NULL);

    char bin[8];

    char * encrypted = NEW (char, ((strlen (message)*8)+1));
    
  	ceasar_encrypt (message);

  	printf ("DEBUG - %s\n", message);

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

    char * decrypted = NEW (char, strlen (message)/8);
    char bin [8];

    int i;
    int j = 0;
    int k = 0;
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


#endif /* _CYPHER_H_*/

