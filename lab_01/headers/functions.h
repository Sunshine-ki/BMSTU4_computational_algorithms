#ifndef _FUNCTINS_H_

#define _FUNCTINS_H_

#include <stdio.h>
#include <math.h>

#include "define.h"

double f(double z);

double method_division(double a, double b);

int fill_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN], int n);

void func(double matrix[MAX_LEN][MAX_LEN], int n, int m, int index[2]);

void print_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN], int n, int m);

double Newton_polynomial(double matrix[MAX_LEN][MAX_LEN], int row, int n, int index[2], double x);

int find_insert(double matrix[MAX_LEN][MAX_LEN], int row, double x, int index[2], int n);

#endif