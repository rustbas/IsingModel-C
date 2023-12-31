#include "isingModel.h"

#define NROW 15
#define NCOL 75

#define NMODEL 25000
#define T 1e6

int main(int argc, char** argv){

    srand(time(0));

    int i, j, c = 0;
    long double p = 0.0;
    long double dE = 0.0;

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
        dE = E(state[1], NROW, NCOL) - E(state[0], NROW, NCOL);
        if (dE > 0.0) {
            for (int i=0; i<NROW; i++) {
                for (int j=0; j<NCOL; j++) {
                    state[0][i][j] = state[1][i][j];
                }
            }
        } else {
            p = energy(state[1], NROW, NCOL, T) / energy(state[0], NROW, NCOL, T);
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
