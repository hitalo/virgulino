#ifndef _HIDER_H_
#define _HIDER_H_

#include "definitions.h"


// proto's ::
char * hide (char * message);
char * unhide (const char * filepath);


// functions ::

/*
 * @note: This function allocates memory dynamically
 * that must be handled by its caller.
 *
 * p.s.: char * revealed must be freed.
 */ 
char *
hide (char * message) {
    char bin[8];
	char * revealed = _NEW (char, ((strlen (message)*8)+1));

    for (int i = 0; i < ((int) strlen (message)); i++) {
        char_to_bin (bin, message [i]);
        strcat (revealed, bin);
    }

    revealed [strlen (revealed)] = 0x00;

    for (int i = 0; i < ((int) strlen (revealed)); i++) {
        if (revealed [i] == '1') {
            revealed [i] = 0x09;
        } else {
            revealed [i] = 0x20;
        } 
    }

    return revealed; // now hidden ::  
}

/*
 * @note: This function allocates dynamic memory
 * that must be handled by its caller.
 *
 * p.s.: char * hidden must be freed.
 */
char *
unhide (const char * filepath) {
    char bin [8];
    int j = 0;
    int k = 0;

    char * message = translate (filepath);

    char * hidden = _NEW (char, strlen (message)/8);
    
    for (int i = 0; i < (int) strlen (message); i++) {
        
        bin [j] = message [i];
        if (j == 7) {
            hidden [k] = bin_to_char (bin);
            k++;
            j = 0;
            continue;
        } 
        j++;

    }
 
    free (message);

    return hidden; // now, revealed ::

}



#endif /* _HIDER_H_ */
