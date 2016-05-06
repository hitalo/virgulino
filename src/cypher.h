#ifndef _CYPHER_H_
#define _CYPHER_H_

#include <stdio.h> 
#include <string.h>
#include <assert.h>

#include "definitions.h"
#include "cypher_utils.h"

#define DEFAULT_SALT                1
#define HIGHER_CHAR                 126     // see ascii table (ENG) - Veja a tabela ascii (PT-BR)
#define LOWER_CHAR                  32      //  "    "     "

// Prototypes :: (ENG)
// Protótipos :: (PT-BR)
void ceasar_encrypt (MessagePack * pack);
void ceasar_decrypt (MessagePack * pack);
void vigenere_encrypt (MessagePack * pack);
void vigenere_decrypt (MessagePack * pack);
void encrypt (MessagePack * pack);
void decrypt (MessagePack * pack);

#endif /* _CYPHER_H_*/