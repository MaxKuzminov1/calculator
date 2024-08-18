#include "rpn.h"

#include <math.h>
#include <stdio.h>

#include "data_structures.h"

token *rpn_conv(token *token_list, int token_list_size, int *rpn_size) {
    stack *op_stack = stack_init();
    token *rpn = malloc(token_list_size * sizeof(token));
    int rpn_index = 0;

    for (int i = 0; i < token_list_size; i++) {
        if (token_list[i].type == NUMBER || token_list[i].type == VARIABLE) {
            rpn[rpn_index++] = token_list[i];
        } else if (token_list[i].int_value == OPENING_PARENTHESIS) {
            push(op_stack, token_list[i]);
        } else if (token_list[i].int_value == CLOSING_PARENTHESIS) {
            while (op_stack->size > 0 && op_stack->top->data.int_value != OPENING_PARENTHESIS) {
                rpn[rpn_index++] = pop(op_stack);
            }
            pop(op_stack);
        } else {
            while (op_stack->size > 0 && op_stack->top->data.priority >= token_list[i].priority) {
                rpn[rpn_index++] = pop(op_stack);
            }
            push(op_stack, token_list[i]);
        }
    }

    while (op_stack->size > 0) {
        rpn[rpn_index++] = pop(op_stack);
    }

    destroy_stack(op_stack);
    *rpn_size = rpn_index;
    return rpn;
}

int binary(stack *op_stack, int oper) {
    token right_operand = pop(op_stack);
    token left_operand = pop(op_stack);
    int err_flag = 0;
    double result = 0;
    switch (oper) {
        case PLUS:
            result = left_operand.double_value + right_operand.double_value;
            break;
        case BINARY_MINUS:
            result = left_operand.double_value - right_operand.double_value;
            break;
        case MULTIPLICATION:
            result = left_operand.double_value * right_operand.double_value;
            break;
        case DIVISION:
            if (right_operand.double_value == 0 && right_operand.type == NUMBER) {
                err_flag = 1;
            } else {
                result = left_operand.double_value / right_operand.double_value;
            }
            break;
    }
    token res_tk = {.type = NUMBER, .double_value = result, .priority = 0};
    push(op_stack, res_tk);
    return err_flag;
}

int unary(stack *op_stack, int oper) {
    token operand = pop(op_stack);
    token result = {.type = NUMBER, .double_value = 0, .priority = 0};
    int err_flag = 0;
    switch (oper) {
        case UNARY_MINUS:
            result.double_value = operand.double_value * -1;
            break;
        case SIN:
            result.double_value = sin(operand.double_value);
            break;
        case COS:
            result.double_value = cos(operand.double_value);
            break;
        case TAN:
            if (fabs(operand.double_value) == 1) {
                err_flag = 1;
            } else {
                result.double_value = tan(operand.double_value);
            }
            break;
        case CTG:
            result.double_value = 1.0 / tan(operand.double_value);
            break;
        case SQRT:
            if (operand.double_value < 0) {
                err_flag = 1;
            } else {
                result.double_value = sqrt(operand.double_value);
            }
            break;
        case LN:
            result.double_value = log(operand.double_value);
            break;
    }
    push(op_stack, result);
    if (err_flag) {
    }
    return err_flag;
}

double rpn_calc(token *rpn, int rpn_size, double x, int *err_flag) {
    stack *op_stack = stack_init();
    for (int i = 0; (i < rpn_size) && (!*err_flag); i++) {
        if (rpn[i].type == NUMBER) {
            push(op_stack, rpn[i]);
        } else if (rpn[i].type == VARIABLE) {
            token var_token = {.type = VARIABLE, .double_value = x, .priority = 0};
            push(op_stack, var_token);
        } else if (rpn[i].int_value < 4) {
            if (binary(op_stack, rpn[i].int_value)) {
                *err_flag = 1;
            }
        } else {
            if (unary(op_stack, rpn[i].int_value)) {
                *err_flag = 1;
            }
        }
    }

    token result = pop(op_stack);

    destroy_stack(op_stack);
    return result.double_value;
}
