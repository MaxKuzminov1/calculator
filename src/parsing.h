#ifndef PARSING_H
#define PARSING_H
#include <stdlib.h>
#include <string.h>

#include "data_structures.h"

token *parse(char *expression, int *tokens_size);
token add_unary_operator(char **expression, int *error_flag);
token add_binary_operator(char **expression, int *error_flag);
token add_number(char **expression, int *error_flag);

#endif