#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

void printState(int *state[], int nrow, int ncol);
int** createState(int nrow, int ncol);
