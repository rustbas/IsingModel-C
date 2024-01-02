#include "isingModel.h"

#ifdef TESTING
#define NROW 15
#define NCOL 50
#define NMODEL 5000
#define T 1e-6
#endif

int main(int argc, char** argv){
    srand(time(0));

    int i, j, c = 0;
    long double p = 0.0;
    long double dE = 0.0;

#ifndef TESTING
    long double T = 0.0;
    int NROW, NCOL;
    long int NMODEL;
    /*printf("Insert number of row: ");*/
    /*scanf("%d", &NROW);*/
    /*printf("Insert number of columns: ");*/
    /*scanf("%d", &NCOL);*/
    /*printf("Insert temperature: ");*/
    /*scanf("%Lf", &T);*/
    /*printf("Insert number of iterations: ");*/
    /*scanf("%ld", &NMODEL);*/

    for (i=0; i<argc; ++i) {
        if (!strcmp(argv[i], "-T") || !strcmp(argv[i], "--temperature")) 
            T = (long double) atof(argv[++i]);
        else if (!strcmp(argv[i], "-nr") || !strcmp(argv[i], "--row-number"))
            NROW = atoi(argv[++i]);
        else if (!strcmp(argv[i], "-nc") || !strcmp(argv[i], "--column-number"))
            NCOL = atoi(argv[++i]);
        else if (!strcmp(argv[i], "-nm") || !strcmp(argv[i], "--iterations"))
            NMODEL = atol(argv[++i]);
    }
#endif

    int** state[2];
    state[0] = createState(NROW, NCOL);
    state[1] = createState(NROW, NCOL);

    for (i=0; i<NROW; ++i) {
        for (j=0; j<NCOL; ++j) {
            state[0][i][j] = 2 * (rand()%2) - 1;
            state[1][i][j] = state[0][i][j];
        }
    }

    for (i=0; i<NMODEL;) {
        randomWalk(state[1], NROW, NCOL);
        dE = E(state[1], NROW, NCOL) - E(state[0], NROW, NCOL);
        if (dE > 0.0) {
            for (int i=0; i<NROW; i++) {
                for (int j=0; j<NCOL; j++) {
                    state[0][i][j] = state[1][i][j];
                }
            }
            ++i;
        } else {
            p = energy(state[1], NROW, NCOL, T) / energy(state[0], NROW, NCOL, T);
            c = coin(p);
            if (c) {
                for (int i=0; i<NROW; i++) {
                    for (int j=0; j<NCOL; j++) {
                        state[0][i][j] = state[1][i][j];
                    }
                }
                ++i;
            } else {
                for (int i=0; i<NROW; i++) {
                    for (int j=0; j<NCOL; j++) {
                        state[1][i][j] = state[0][i][j];
                    }
                }
            }
        }
        /*printf("%d %f\n", c, p);*/
        printStateEscape(state[0], NROW, NCOL);
    }

    for (i=0; i<NROW; i++) {
        free(state[0][i]);
        free(state[1][i]);
    }

    printf("\033[2J\n");

    return 0;
}
