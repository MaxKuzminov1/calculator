#ifndef RPN_H
#define RPN_C
#include "data_structures.h"
token *rpn_conv(token *token_list, int token_list_size, int *rpn_list_size);
double rpn_calc(token *rpn, int rpn_size, double x, int *err_flag);
int binary(stack *op_stack, int oper);
int unary(stack *op_stack, int oper);
int oper(int token_list_size, int rpn_index, stack *op_stack, token *rpn, token tk);

#endif
