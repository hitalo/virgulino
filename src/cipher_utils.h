#ifndef _CIPHER_UTILS_H_
#define _CIPHER_UTILS_H_

#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <assert.h>

#include "definitions.h"

// prototypes ::
void char_to_bin (char * bin, char c);
char bin_to_char (char * bin);

char * translate (const char * filepath);
char * new_random_Key (char * message);

// Functions ::

/*
 * @desc: just for debug
 */ 
void 
debug (short i) {
    printf ("[DEBUG] %d\n", i);
}

/*
 * @desc: As the name suggests, cast char into bin.
 */ 
void
char_to_bin (char * bin, char c) {
  	assert (bin != NULL);
    int i;
  	int j;
    
    for (j = 0, i = 7; i >= 0; i--, j++) {
        bin [j] = ( (c & (1 << i)) ? '1' : '0');
    }
    bin [8] = 0x00;
}


/*
 * @desc: cast bin into char.
 */ 
char 
bin_to_char (char * bin) {
    assert (bin != NULL);

    char c = 0x00;
    int i;

    for (i = 0; i < 8; i++) {
        if (bin [i] == '1') {
            c |= 1 << (7 - i);       
        }
    }
    return c;
}


/*
 * @desc: Translates 0x09 and 0x20 into 0's and 1's::
 * Note:
 * It allocates dynamoc memory that must be handled by the its caller
 */
char *
translate (const char * filepath) {
    assert (filepath != NULL);

    int i = 0;
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


/*
 * This function will generate a random key based on
 * message length.
 * Note:
 * It allocates dynamic memory that must be handled by it's caller ::
 */
char *
new_random_key (char * message) {
    size_t msg_len = strlen (message);
    size_t i = 0;

    char * key = NEW (char, msg_len);

    srand (time (NULL));

    int c = 0;
    for (i = 0; i < msg_len; ++i) {
        do {
            c = rand () % 127;
        } while (c <= 31); 
        key [i] = c;
    }
    
    return key;
}

#endif /* _CIPHER_UTILS_H_ */
