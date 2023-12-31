
#include "isingModel.h"

#define NROW 15
#define NCOL 75

#define NMODEL 10000
#define T 1e1

int main(int argc, char** argv){

    int i, j, c = 0;
    double p = 0.0;

    int** state[2];
    state[0] = createState(NROW, NCOL);
    state[1] = createState(NROW, NCOL);

    for (i=0; i<NROW; ++i) {
        for (j=0; j<NCOL; ++j) {
            state[0][i][j] = 2 * (rand()%2) - 1;
            state[1][i][j] = state[0][i][j];
        }
    }

    for (i=0; i<NMODEL; i++) {
        randomWalk(state[1], NROW, NCOL);
        p = energy(state[1], NROW, NCOL, T) / energy(state[0], NROW, NCOL, T);
        if (p > 1.0f) {
            for (int i=0; i<NROW; i++) {
                for (int j=0; j<NCOL; j++) {
                    state[0][i][j] = state[1][i][j];
                }
            }
        } else {
            c = coin(p);
            if (c) {
                for (int i=0; i<NROW; i++) {
                    for (int j=0; j<NCOL; j++) {
                        state[0][i][j] = state[1][i][j];
                    }
                }
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

    return 0;
}
