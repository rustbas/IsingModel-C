#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef UNISTD_H
#define UNISTD_H
#include <unistd.h>
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

void printStateEscape(int *state[], int nrow, int ncol) {
    char pos = '#', neg = '@';
    for (int i=0; i<nrow; i++) {
        for (int j=0; j<ncol; j++) {
            if (state[i][j] == 1) printf("%c", pos);
            else printf("%c", neg);
        }

        printf("\n");
    }

    printf("\033[%dA", nrow);
    printf("\033[%dD", ncol);

    usleep(10*1000);

}

int** createState(int nrow, int ncol) {
    int i;
    int** state;
    state = (int**) malloc(nrow * sizeof(int*));
    for (i=0; i<nrow; ++i) {
        state[i] = (int*) malloc(ncol * sizeof(int));
    }

    return state;
}

void randomWalk(int *state[], int nrow, int ncol) {
    int i = rand()%nrow;
    int j = rand()%ncol;
    state[i][j] = -state[i][j];
}

int E(int *state[], int nrow, int ncol) {
    int result = 0;

    for (int i=1; i<nrow; i++) {
        for (int j=0; j<ncol; j++) {
            result += state[i][j] * state[i-1][j];
        }
    }

    for (int i=0; i<nrow; i++) {
        for (int j=1; j<ncol; j++) {
            result += state[i][j] * state[i][j-1];
        }
    }

    return result;
}

double energy(int *state[], int nrow, int ncol, float T) {
    return exp(-E(state, nrow, ncol)/T);
}
