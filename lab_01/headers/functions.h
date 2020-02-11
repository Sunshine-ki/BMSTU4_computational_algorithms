#ifndef _FUNCTINS_H_

#define _FUNCTINS_H_

#include <stdio.h>

#define MAX_LEN 10
#define MODE_READ "r"
#define OK 0
#define ERROR_FIND -1

int fill_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN], int n);

void print_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN], int n, int m);

int find_insert(double matrix[MAX_LEN][MAX_LEN], int row, double x, int index[2], int n);

void func(double matrix[MAX_LEN][MAX_LEN], int n, int m, int index[2]);

#endif