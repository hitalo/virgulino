#include <stdio.h>

#include "../cipher_utils.h"


int
main(int argc, char ** argv) {
    char * key = NULL;

    if (argc < 2) {
        printf ("usage: %s <message>\n", argv[0]);
        return EXIT_SUCCESS;
    }

    key = new_random_key (argv[1]);

    printf ("Key: \"%s\"\n", key);

    free(key);

    return EXIT_SUCCESS;
}
