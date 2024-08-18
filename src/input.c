#include "input.h"

#include <math.h>
#include <stdlib.h>

char *get_expression() {
    char *expression = (char *)malloc(sizeof(char));
    char symbol;
    int size = 1, error_flag = 0;
    while ((symbol = getchar()) != '\n') {
        expression[size - 1] = symbol;
        char *tmp = (char *)realloc(expression, sizeof(char) * ++size);
        if (tmp != NULL) {
            expression = tmp;
        } else {
            error_flag = 1;
            break;
        }
    }
    if (!error_flag) {
        char *tmp = (char *)realloc(expression, sizeof(char) * ++size);
        if (tmp != NULL) {
            expression = tmp;
            expression[size - 1] = '\0';
        } else {
            error_flag = 1;
        }
    }
    if (error_flag) {
        free(expression);
        expression = NULL;
    }
    return expression;
}