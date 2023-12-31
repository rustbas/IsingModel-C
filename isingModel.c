#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

void printState(int *state[], int nrow, int ncol) {
    char pos = '#', neg = '@';
    for (int i=0; i<nrow; i++) {
        for (int j=0; j<ncol; j++) {
            if (state[i][j] == 1) printf("%c", pos);
            else printf("%c", neg);
        }

        printf("\n");
    }
}
