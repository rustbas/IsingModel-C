
#include "isingModel.h"

#define NROW 15
#define NCOL 35

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

    /*printf("Hello, world!\n");*/

    printState(state[0], NROW, NCOL);

    return 0;
}
