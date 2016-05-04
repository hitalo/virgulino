#include "definitions.h"

//functions ::
void
init_message_pack (MessagePack * pack) {
    pack->message = NULL;
    pack->filepath = NULL;
    pack->key = NULL;

    pack->message_len = 0;
    
    pack->encode = false;
    pack->encode_type.vigenere = false;
    pack->encode_type.ceasar = false;
    pack->encode_type.rand_numbs = false;

}

void
destroy_message_pack (MessagePack * pack) {
    assert (pack);
    assert (pack->message);

    free (pack->message);

   /* if (pack->key)
        free (pack->key);
   */
   /* if (pack->filepath)
        free (pack->filepath);*/
}