#include "graph_output.h"

double drawGraph(token *rpn, int rpn_size) {
    double stepX = END_X / WIDTH;
    //double stepY = (MAX_Y - MIN_Y) / (HEIGHT - 1);
    double fx;
    // char graph[HEIGHT][WIDTH];
    // for (int y = 0; y < HEIGHT; ++y) {
    //     for (int x = 0; x < WIDTH; ++x) {
    //         graph[y][x] = '.';
    //     }
    // }
    int err_flag = 0;
    for (int x = 0; x < WIDTH && (!err_flag); ++x) {
        fx = rpn_calc(rpn, rpn_size, x * stepX, &err_flag);
        if (err_flag) {
            printf("THERE IS A MISTAKE IN EXPRESSION");
        } else {
            //int graphY = round(HEIGHT - (fx - MIN_Y) / stepY);
            // if (graphY > 0 && graphY < HEIGHT + 1) {
            //     graph[graphY - 1][x] = '*';
            // }
        }
    }

    // for (int y = HEIGHT - 1; y >= 0 && (!err_flag); y--) {
    //     for (int x = 0; x < WIDTH; x++) {
    //         printf("%c", graph[y][x]);
    //     }
    //     printf("\n");
    // }
    return fx;
}
