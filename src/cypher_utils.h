#ifndef _CYPHER_UTILS_H_H_
#define _CYPHER_UTILS_H_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <assert.h>

#include "definitions.h"

// prototypes ::

void debug (short i);

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
 * @desc: As the name suggests, it casts a char into bin.
 */ 
void
char_to_bin (char * bin, char c) {
  	assert (bin != NULL);

    for (int j = 0, i = 7; i >= 0; i--, j++) {
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

    for (int i = 0; i < 8; i++) {
        if (bin [i] == '1') {
            c |= 1 << (7 - i);       
        }
    }
    return c;
}


/*
 * @desc: Translates 0x09 and 0x20 into 0's and 1's::
 * Note:
 * It allocates dynamic memory that must be handled by the its caller
 *
 * @obs: char * content is dynamic allocated and must be freed.
 */
char *
translate (const char * filepath) {
    assert (filepath != NULL);

    FILE * fp = fopen (filepath, "r");
    if (fp == NULL) {
        printf ("Error opening the file [!!]\n");
        exit (-1);
    }

    fseek (fp, 0L, SEEK_END);
    long int file_size = ftell (fp);
    rewind (fp);

    char * content = _NEW (char, file_size);

    for (int i = 0; i < (file_size); i++) 
        (fgetc (fp) == 0x09) ? (content [i] = '1') : (content [i] = '0');

    return content; // @note: Caller must free it.

}


/*
 * This function will generate a random key based on
 * message length.
 * Note:
 * It allocates dynamic memory that must be handled by it's caller ::
 *
 * @obs: char * key is dynamic allocated and must be freed.
 */
char *
new_random_key (char * message) {

        size_t msg_len = strlen (message);
        size_t i = 0;

        char * key = _NEW (char, msg_len);
        FILE * fp = fopen ("/dev/urandom", "r");
        fread (key, 1, msg_len, fp);
        fclose (fp);
        
        for (i = 0; i < msg_len; i++) {
            key[i] = abs(key[i]) % (HIGHER_CHAR + 1);
            if (key[i] < LOWER_CHAR) key[i] = (HIGHER_CHAR + 1) + (key[i] - LOWER_CHAR);
        }

        return key; // @note: Caller must free it ::
}

#endif /* _CYPHER_UTILS_H_H_ */

