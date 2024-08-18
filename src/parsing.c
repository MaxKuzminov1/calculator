
#include "parsing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_structures.h"

token *parse(char *input_expression, int *tokens_size) {
    int error_flag = 0;
    char *expression = input_expression;
    token *tokens = (token *)malloc(sizeof(token));
    *tokens_size = 0;
    int operator_balance = 1;
    int brackets_balance = 0;

    while (*expression && !error_flag) {
        token *tmp = (token *)realloc(tokens, sizeof(token) * (*tokens_size + 1));
        if (tmp != NULL) {
            tokens = tmp;
        } else {
            error_flag = 1;
            break;
        }
        if (*expression == ' ') {
        } else if (*expression >= '0' && *expression <= '9') {
            tokens[*tokens_size] = add_number(&expression, &error_flag);
            (*tokens_size)++;
            operator_balance--;
        } else if (*expression == 'x' || *expression == 'X') {
            token variable_x;
            variable_x.type = VARIABLE;
            variable_x.priority = 0;
            variable_x.int_value = 0;
            tokens[*tokens_size] = variable_x;
            (*tokens_size)++;
            operator_balance--;
        } else if (*expression == '(') {
            token bracket;
            bracket.type = OPERATOR;
            bracket.int_value = OPENING_PARENTHESIS;
            bracket.priority = 0;
            brackets_balance++;
            tokens[*tokens_size] = bracket;
            (*tokens_size)++;
        } else if (*expression == ')') {
            token bracket;
            bracket.type = OPERATOR;
            bracket.int_value = CLOSING_PARENTHESIS;
            bracket.priority = 0;
            brackets_balance--;
            tokens[*tokens_size] = bracket;
            (*tokens_size)++;
        } else if (operator_balance == 1) {
            tokens[*tokens_size] = add_unary_operator(&expression, &error_flag);
            (*tokens_size)++;
        } else if (operator_balance == 0) {
            tokens[*tokens_size] = add_binary_operator(&expression, &error_flag);
            (*tokens_size)++;
            operator_balance++;
        } else {
            error_flag = 1;
        }

        if (brackets_balance < 0 || (operator_balance != 0 && operator_balance != 1)) {
            error_flag = 1;
        }

        expression++;
    }

    if (brackets_balance != 0 || operator_balance != 0) {
        error_flag = 1;
    }

    if (error_flag) {
        free(tokens);
        tokens = NULL;
        *tokens_size = 0;
    }
    return tokens;
}

token add_number(char **expression, int *error_flag) {
    int dots_cnt = 0;
    char *number_end = *expression;
    token number;
    number.type = NUMBER;
    number.priority = 0;
    number.double_value = 0;

    while ((*number_end >= '0' && *number_end <= '9') || *number_end == '.') {
        if (*number_end == '.') {
            dots_cnt++;
        }
        number_end++;
    }

    if (dots_cnt > 1) {
        *error_flag = 1;
    } else {
        char tmp = *number_end;
        *number_end = '\0';
        number.double_value = atof(*expression);
        *number_end = tmp;
        *expression = number_end - 1;
    }

    return number;
}

token add_binary_operator(char **expression, int *error_flag) {
    token operator;
    operator.type = OPERATOR;
    operator.priority = 0;
    operator.int_value = 0;

    switch (**expression) {
        case '-':
            operator.int_value = BINARY_MINUS;
            operator.priority = 1;
            break;
        case '+':
            operator.int_value = PLUS;
            operator.priority = 1;
            break;
        case '*':
            operator.int_value = MULTIPLICATION;
            operator.priority = 2;
            break;
        case '/':
            operator.int_value = DIVISION;
            operator.priority = 2;
            break;
        default:
            *error_flag = 1;
    }

    return operator;
}

token add_unary_operator(char **expression, int *error_flag) {
    token operator;
    operator.type = OPERATOR;
    operator.priority = 4;
    operator.int_value = 0;

    switch (**expression) {
        case '-':
            operator.priority = 4;
            operator.int_value = UNARY_MINUS;
            break;
        case 's':
            if (strncmp(*expression, "sin(", 4) == 0) {
                operator.int_value = SIN;
                *expression += 2;
            } else if (strncmp(*expression, "sqrt(", 5) == 0) {
                operator.int_value = SQRT;
                *expression += 3;
            } else {
                *error_flag = 1;
            }
            break;
        case 'c':
            if (strncmp(*expression, "ctg(", 4) == 0) {
                operator.int_value = CTG;
                *expression += 2;
            } else if (strncmp(*expression, "cos(", 4) == 0) {
                operator.int_value = COS;
                *expression += 2;
            } else {
                *error_flag = 1;
            }
            break;
        case 'l':
            if (strncmp(*expression, "ln(", 2) == 0) {
                operator.int_value = LN;
                *expression += 1;
            } else {
                *error_flag = 1;
            }
            break;
        case 't':
            if (strncmp(*expression, "tan(", 4) == 0) {
                operator.int_value = TAN;
                *expression += 2;
            } else {
                *error_flag = 1;
            }
            break;
        default:
            *error_flag = 1;
    }

    return operator;
}
