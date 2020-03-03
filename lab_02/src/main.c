#include <stdio.h>

#include "functions.h"
#include "matrix_func.h"
#include "define.h"
#include "colors.h"

// table = (3, 7, 1) (x + y)
// table2 = (-3, 4, 1.5) (x*x + y*y)
// table3 = (-1, 1, 0.25) (sin(x) + cos(y))
int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], MODE_READ);
    double matrix[MAX_LEN][MAX_LEN], x, y;
    int nx, ny;
    int index[2];

    yellow();
    printf("Введите nx и ny: ");
    if (scanf("%d %d", &nx, &ny) != 2 || nx <= 0 || ny <= 0)
    {
        printf("Некорректный ввод.\n");
        return ERROR_INPUT;
    }
    printf("Введите x и y: ");
    if (scanf("%lf %lf", &x, &y) != 2)
    {
        printf("Некорректный ввод.\n");
        return ERROR_INPUT;
    }
    white();

    int size_matrix = fill_matrix(f, matrix);

    bilinear_interpolation(matrix, size_matrix, x, y, nx, ny);

    // print_matrix(stdout, matrix, size_matrix, size_matrix);

    white();
    fclose(f);
    return OK;
}