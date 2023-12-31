
#include "isingModel.h"

#define NROW 5
#define NCOL 35

#define NMODEL 1000

int main(int argc, char** argv){

    int i, j;

    int** state[2];
    state[0] = createState(NROW, NCOL);
    state[1] = createState(NROW, NCOL);

    for (i=0; i<NROW; ++i) {
        for (j=0; j<NCOL; ++j) {
            state[0][i][j] = 2 * (rand()%2) - 1;
            state[1][i][j] = state[0][i][j];
        }
    }

    /*printState(state[0], NROW, NCOL);*/

    for (i=0; i<NMODEL; i++) {
        randomWalk(state[0], NROW, NCOL);
        printStateEscape(state[0], NROW, NCOL);
    }

    printf("\n");

    return 0;
}
