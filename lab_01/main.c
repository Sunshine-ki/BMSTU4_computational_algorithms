#include <stdio.h>

#include "headers/functions.h"

#define OK 0

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], MODE_READ);
    double matrix[MAX_LEN][MAX_LEN], x;
    int n;
    int index[2];

    printf("Введите степень: ");
    scanf("%d", &n);
    printf("Введите x: ");
    scanf("%lf", &x);

    int row = fill_matrix(f, matrix, n);
    int err = find_insert(matrix, row, x, index, n);
    if (err)
    {
        return err;
    }
    func(matrix, row, n, index);

    double result = Newton_polynomial(matrix, row, n, index, x);
    printf("result: y = %f\n", result);

    // print_matrix(stdout, matrix, row, n);

    fclose(f);
    return OK;
}