#ifndef _CYPHER_H_
#define _CYPHER_H_

#include <stdio.h> 
#include <string.h>
#include <assert.h>

#include "definitions.h"
#include "cypher_utils.h"

#define DEFAULT_SALT                1
#define HIGHER_CHAR                 126     // see ascii table
#define LOWER_CHAR                  32      //  "    "     "

// Prototypes ::
void ceasar_encrypt (MessagePack * pack);
void ceasar_decrypt (MessagePack * pack);
void vigenere_encrypt (MessagePack * pack);
void vigenere_decrypt (MessagePack * pack);
void encrypt (MessagePack * pack);
void decrypt (MessagePack * pack);


void 
ceasar_encrypt (MessagePack * pack) {
    assert (NULL != pack);
    assert (pack->encode_type.ceasar);
    assert (NULL != pack->message);

  	for (int i = 0; i < pack->message_len; i++) 
	  	pack->message[i] = ( (pack->message[i] + pack->salt) <= HIGHER_CHAR
                                ? pack->message[i] + pack->salt
                                : ( (LOWER_CHAR - 1) + ( (pack->message[i] + pack->salt) - HIGHER_CHAR) ) );
	
}

void
ceasar_decrypt (MessagePack * pack) {
    assert (NULL != pack);
    assert (pack->encode_type.ceasar);
    assert (NULL != pack->message);
 
  	for (int i = 0; i < pack->message_len; i++) 
        pack->message[i] = ( (LOWER_CHAR <= pack->message[i] - pack->salt)
                                ? pack->message[i] - pack->salt
                                : ( (HIGHER_CHAR + 1) - (LOWER_CHAR - (pack->message[i] - pack->salt) ) ) );
                                
}

void 
vigenere_encrypt (MessagePack * pack) {
  	assert (pack->message != NULL);
    assert (pack->encode_type.vigenere);  

    int cn = 0;
    
    for (int i = 0; i <= pack->message_len; i++) {

        if (i > 0) 
            pack->message [(i - 1)] = cn;
        
        for (cn = ((int)(pack->message[i])) + ((int)(pack->key[i])); cn > HIGHER_CHAR; cn = LOWER_CHAR + (cn % HIGHER_CHAR)); 
    }
}

// to decrypt vigenere cypher, the end-user must provide the key.
void
vigenere_decrypt (MessagePack * pack){
    assert (NULL != pack->message);
    assert (NULL != pack->key);
    assert (pack->encode_type.vigenere);

    int cn = 0;

    for (int i = 0; i <= pack->message_len; i++) {
        if (i > 0) 
            pack->message [(i - 1)] = cn;

        for (cn = ((int) pack->message[i] - ((int)pack->key[i])); cn < LOWER_CHAR; cn = HIGHER_CHAR - (LOWER_CHAR -cn));
   }
}

// Interface to encrypt using whatever cypher choosen by the end-user.
void
encrypt (MessagePack * pack) {
  	assert (NULL != pack);

    // To add new cyphers just add an if to this list and the proper cypher functions ::
    if (pack->encode_type.ceasar) 
        ceasar_encrypt (pack);
    
    if (pack->encode_type.vigenere)
        vigenere_encrypt (pack);
   // printf ("Message: %s\n", pack->message);
       
}

void
decrypt (MessagePack * pack) { 
  	assert (NULL != pack);

    if (pack->encode_type.ceasar)
        ceasar_decrypt (pack);

    if (pack->encode_type.vigenere)
        vigenere_decrypt (pack);

}

#endif /* _CYPHER_H_*/

