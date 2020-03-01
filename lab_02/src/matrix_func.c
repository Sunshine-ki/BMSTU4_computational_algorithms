#include "matrix_func.h"

int fill_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN])
{
    int row;
    fscanf(f, "%d", &row);
    row++;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
            fscanf(f, "%lf", &matrix[i][j]);
    }

    // if (n > MAX_LEN)
    //     n = MAX_LEN - 1;
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 2; j < n; j++)
    //         matrix[i][j] = 0;
    // }

    return row;
}

// Функция обнуляет столбцы матрицы, начиная со 2-го.
void reset_matrix(double matrix[MAX_LEN][MAX_LEN], int n, int m)
{
    // puts("");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 2; j < m + 2; j++)
    //         matrix[i][j] = 0;
    // }
}

// Выводит матрицу на экран.
void print_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN], int n, int m)
{
    fprintf(f, "\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(f, "%-10lf ", matrix[i][j]);
        fprintf(f, "\n");
    }
}