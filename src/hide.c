#include "hide.h"

// functions :: (ENG)
// funções   :: (PT-BR)

/*
 * ENGLISH:
 * @note: This function allocates memory dynamically
 * that must be handled by its caller.
 *
 * p.s.: char * revealed must be freed.
 *
 *
 * PT-BR:
 * @nota: Esta função aloca memória dinamicamente
 * que precisa ser manipulada pelo seu chamador.
 *
 * p.s.: char * revelado deve ser liberado.
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

    return revealed; // now hidden      :: (ENG)
					 // agora escondido :: (PT-BR)
}

/*
 * ENGLISH: 
 * @note: This function allocates dynamic memory
 * that must be handled by its caller.
 *
 * p.s.: char * hidden must be freed.
 *
 *
 * PT-BR:
 * @nota: Esta função aloca memória dinâmica
 * que precisa ser liberada por seu chamador.
 *
 * p.s.: char * revelado deve ser liberado.
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

    return hidden; // now, revealed   :: (ENG)
				   // agora, revelado :: (PT-BR)
}
