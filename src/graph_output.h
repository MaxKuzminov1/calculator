#ifndef GRAPH_OUTPUT
#define GRAPH_OUTPUT
#include <math.h>
#include <stdio.h>

#include "data_structures.h"
#include "rpn.h"

#define WIDTH 80
#define HEIGHT 25
#define START_X 0
#define END_X 4 * M_PI
#define MIN_Y -1.0
#define MAX_Y 1.0
double drawGraph(token *rpn, int rpn_size);

#endif
