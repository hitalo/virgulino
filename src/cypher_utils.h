#ifndef _CYPHER_UTILS_H_H_
#define _CYPHER_UTILS_H_H_

// prototypes :: (ENG)
// protótipos :: (PT-BR)

void debug (short i);

void char_to_bin (char * bin, char c);
char bin_to_char (char * bin);

char * translate (const char * filepath);
char * new_random_key (char * message);

#endif /* _CYPHER_UTILS_H_H_ */