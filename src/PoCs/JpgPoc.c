#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JPG_FILE   "sample.jpg"

int
main (void) {
    
    const char * str = "TEST";
    size_t i;
    int bit_idx;
    FILE * fp;
    char c;
    fp = fopen (JPG_FILE, "rb+");
    if (fp == NULL) {
        printf ("[ERROR] fail to open %s [!!]\n", JPG_FILE);
        exit (-1);
    }
    
    fseek(fp, 0, SEEK_END);

    fprintf (fp, "%s", str);
    /*
    for (i = 0; i < strlen (str); ++i) {
    unsigned char byte = (unsigned char)str[i];
        for (bit_idx = 0; bit_idx < 8; ++bit_idx) {
            fputs ( ( ( (byte  & (1 << bit_idx) ) != 0 ) 
                        ? "1\n" 
                        : "0\n"), fp);

        }
    }*/
    fclose(fp);
    return 0;
}
