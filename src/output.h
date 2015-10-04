#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <stdio.h>
#include <string.h>

#include "color_set.h"

void splash (void);

 
void 
splash (void) {
    printf ("%s"\
            "******************************************************\n"\
            "*         __                    __ __                *\n"\
            "* .--.--.|__|.----.-----.--.--.|  |__|.-----.-----.  *\n"\
            "* |  |  ||  ||   _|  _  |  |  ||  |  ||     |  _  |  *\n"\
            "*  \\___/ |__||__| |___  |_____||__|__||__|__|_____|  *\n"\
            "*                 |_____|                            *\n"\
            "*                                                    *\n"\
            "* Virgulino v0.1                                     *\n"\
            "* coded by:                                          *\n"\
            "*      n3k00n3   -   nekoone (at) riseup(dot)net     *\n"\
            "*      UserX     -   user_x(at)riseup(dot_net        *\n"\
            "*      Cascudo                                       *\n"\
            "*      gjuniioor -   gjuniioor@protonmail.ch         *\n"\
            "* LampiaoSEC - Security Research Group               *\n"\
            "* #lampiaosec at freenode                            *\n"\
            "* https://lampiaosec.github.io                       *\n"\
            "*                                                    *\n"\
            "******************************************************\n\n%s", 
            T_GREEN, T_NULL);

}

#endif /* _OUTPUT_H_ */

