#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef TIME_H
#define TIME_H
#include <time.h>
#endif

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

void printState(int *state[], int nrow, int ncol);
void printStateEscape(int *state[], int nrow, int ncol);
int** createState(int nrow, int ncol);
void randomWalk(int *state[], int nrow, int ncol);
int E(int *state[], int nrow, int ncol);
long double energy(int *state[], int nrow, int ncol, long double T);
int coin(long double p);
