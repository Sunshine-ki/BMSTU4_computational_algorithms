#ifndef _MATRIX_FUNC_H_

#define _MATRIX_FUNC_H_

#include <stdio.h>
#include "define.h"

void reset_matrix(double matrix[MAX_LEN][MAX_LEN], int n, int m);

int fill_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN], int n);

void print_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN], int n, int m);

#endif