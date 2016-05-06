#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "color_set.h"
#include "definitions.h"

// prototypes ::
void err_msg (const char * err);

void help (void);
void usage (const char * itself);

bool to_file (const char * filepath, char * binmsg);
void save_key (const char * key);



#endif /* _OUTPUT_H_ */

