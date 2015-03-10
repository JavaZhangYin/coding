#ifndef _PARSE_OPTIONS_H_
#define _PARSE_OPTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h> // for isprint.
#include "defs.h" 

void parseOptions(int argc, char** argv, DELAYS *dlys);

#endif
