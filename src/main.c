#include "output.h"
#include "cypher.h"

int 
main (int argc, char ** argv) {

    char * decrypted = NULL;
    if (argc < 2) {
        splash ();
        printf ("Usage: %s <message>\n", argv[0]);
        exit (-11);
    }
   
    splash ();
    decrypted = decrypt (translate ("teste"));

    printf ("decrypted: %s\n", decrypted);

    free (decrypted);
    return 0;
}


