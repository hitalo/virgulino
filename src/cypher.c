#include <stdio.h> 
#include <string.h>
#include <assert.h>

#include "definitions.h"
#include "cypher_utils.h"
#include "cypher.h"

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

// to decrypt vigenere cypher, the end-user must provide the key. (ENG)
// para descriptografar a cifra de Vigenère, o usuário final deve fornecer a chave. (PT-BR)
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

// Interface to encrypt using whatever cypher choosen by the end-user. (ENG)
// Interface para criptografar utilizando qualquer cifra escolhida pelo usuário final. (PT-BR)
void
encrypt (MessagePack * pack) {
  	assert (NULL != pack);

    // To add new cyphers just add an if to this list and the proper cypher functions :: (ENG)
	// Para adicionar novas cifras, apenas adicione um if nesta lista e as funções apropriadas de cifra :: (PT-BR)
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