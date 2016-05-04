#ifndef _VIRGULINO_H_
#define _VIRGULINO_H_

#include "definitions.h"
#include "output.h"
#include "color_set.h"
#include "cypher.h"
#include "hide.h"

#include <string.h>

#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>

// prototypes ::
void handler (char argc, char ** argv);
void verify_params (MessagePack * pack);
void engine (MessagePack * pack);

#endif /* _VIRGULINO_H_ */