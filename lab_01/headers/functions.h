#ifndef _FUNCTINS_H_

#define _FUNCTINS_H_

#include <stdio.h>
#include <math.h>

#include "define.h"

double f(double x, double matrix[MAX_LEN][MAX_LEN], int row, int n, int index[2]);

double method_division(double a, double b, double matrix[MAX_LEN][MAX_LEN], int row, int n, int index[2]);

void func(double matrix[MAX_LEN][MAX_LEN], int n, int m, int index[2]);

double Newton_polynomial(double matrix[MAX_LEN][MAX_LEN], int row, int n, int index[2], double x);

int find_insert(double matrix[MAX_LEN][MAX_LEN], int row, double x, int index[2], int n);

#endif