#include "matrix_func.h"

// Функция обнуленяет значения матрицы
// И  записывает в первые два столбца значения
// Из файла (x и y).
int fill_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN], int n)
{
    // Считывает из файла кол-во рядов.
    int row;
    fscanf(f, "%d", &row);

    // Считывает x и y.
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2; j++)
            fscanf(f, "%lf", &matrix[i][j]);
    }
    if (n > MAX_LEN)
        n = MAX_LEN - 1;
    // Обнуляет оставшиеся значения.
    for (int i = 0; i < row; i++)
    {
        for (int j = 2; j < n; j++)
            matrix[i][j] = 0;
    }

    return row;
}

// Функция обнуляет столбцы матрицы, начиная со 2-го.
void reset_matrix(double matrix[MAX_LEN][MAX_LEN], int n, int m)
{
    puts("");
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < m + 2; j++)
            matrix[i][j] = 0;
    }
}

// Выводит матрицу на экран.
void print_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN], int n, int m)
{
    puts("");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m + 2; j++)
            fprintf(f, "%lf ", matrix[i][j]);
        fprintf(f, "\n");
    }
}