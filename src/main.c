#include "output.h"
#include "cypher.h"

int 
main (int argc, char ** argv) {

    if (argc < 2) {
        splash ();
        printf ("Usage: %s <message>\n", argv[0]);
        exit (-11);
    }
   
    //char * decrypted = NULL;
    splash ();
    /*  decrypted = decrypt (translate ("teste"));

    printf ("decrypted: %s\n", decrypted);

    free (decrypted);*/
    help ();
    return 0;
}


