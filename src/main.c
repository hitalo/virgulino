#include <string.h>

#include "output.h"
#include "cypher.h"



int 
main (int argc, char ** argv) {

    char * encrypted = NULL;

    if (argc < 2) {
        splash ();
        printf ("Usage: %s <message>\n", argv[0]);
        exit (-11);
    }

    encrypted = encrypt (argv[1]);
    
    splash ();
    printf ("%s\n", encrypted);

    free (encrypted);
    return 0;
}
