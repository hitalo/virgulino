#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#include <stdlib.h>
#include <string.h>

#define SW_NAME                "virgulino"

// macros ::
#define NEW(type,size)         ((type *)malloc(sizeof(type) * size))

#define BOOL    unsigned char
#define TRUE    1
#define FALSE   0

// error control ::
typedef enum error_n errorn_t;
enum error_n {
    NO_ERROR,
    MIS_LEN,
    MIS_CHARSET,
};

errorn_t errorn;

// prototypes ::
BOOL chartset_verify (char * txt); 
void error (const char * err_msg);


//functions ::
BOOL
charset_verify (char * txt) {
    int i;
    for (i = 0; i < strlen (txt); i++) {
        if (txt[i] < 0 || txt[i] > 126) {
            errorn = MIS_CHARSET;
            return FALSE;
        }
    }


    return TRUE;
}

void error (const char * err_msg) {
   switch (errorn) {
       case (MIS_LEN): {
           printf ("Error: buffers with differente size - %s\n", err_msg);
           break;

       } case  (MIS_CHARSET): {
           printf ("Error: invalid charset - %s\n", err_msg);
           break;

       } default: {
           break;

       }
   }
}

#endif /* _DEFINITIONS_H_ */

