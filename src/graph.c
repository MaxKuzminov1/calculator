#include "graph.h"

double result_output(char output_buffer[100]) {
    char *exp_in = output_buffer;
    double fun = 0;
    if (exp_in == NULL) {
        printf("ERROR IN GETTING EXPRESSION");
    } else {
        int tokens_size;
        token *tokens = parse(exp_in, &tokens_size);
        if (tokens == NULL) {
            printf("ERROR IN PARSING EXPRESSION");
        } else {
            int rpn_size = 0;
            token *rpn = rpn_conv(tokens, tokens_size, &rpn_size);
            fun = drawGraph(rpn, rpn_size);
            //printf(" %lf\n",drawGraph(rpn, rpn_size));
            free(rpn);
            //printf(" %lf\n",fun);
        }
        free(tokens);
    }
    //free(exp_in);
    //printf("%lf",fun);
    return fun;
}
