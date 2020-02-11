#include "headers/functions.h"

int fill_matrix(FILE *f, double matrix[MAX_LEN][MAX_LEN], int n)
{
    int row;
    fscanf(f, "%d", &row);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2; j++)
            fscanf(f, "%lf", &matrix[i][j]);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 2; j < n; j++)
            matrix[i][j] = 0;
    }

    return row;
}

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

int find_insert(double matrix[MAX_LEN][MAX_LEN], int row, double x, int index[2], int n)
{
    int a, b, k;

    for (int i = 0; i < row - 1; i++)
    {
        if (matrix[i][0] <= x && x <= matrix[i + 1][0] || matrix[i][0] >= x && x >= matrix[i + 1][0])
        {
            a = b = (n - 1) / 2;
            if ((n - 1) % 2)
                a++;

            index[0] = i - a;
            index[1] = i + b + 1;

            // printf("Значения: %lf %lf\n", matrix[i][0], matrix[i + 1][0]);
            // printf("Индексы ДО: %d %d\n", i, i + 1);
            // printf("\na = %d b = %d\n", a, b);

            if (index[0] < 0)
            {
                index[1] += -1 * index[0];
                index[0] = 0;
            }
            if (index[1] >= row)
            {
                index[0] -= index[1] - (row - 1);
                index[1] = row - 1;
            }
            // printf("row = %d\n", row);
            // printf("Индексы ПОСЛЕ: %d %d\n", index[0], index[1]);

            return OK;
        }
    }
    printf("Экстрополяция! (Выход за пределы)");
    return ERROR_FIND;
}

void func(double matrix[MAX_LEN][MAX_LEN], int n, int m, int index[2])
{
    m += 2;
    // printf("\nИндексы: %d %d\n", index[0], index[1]);
    for (int j = 2, k = 1; j < m; j++, k++)
    {
        for (int i = index[0]; i < index[1]; i++)
        {
            matrix[i][j] = (matrix[i][j - 1] - matrix[i + 1][j - 1]) / (matrix[i][0] - matrix[i + k][0]);
        }
        index[1]--;
    }
    // printf("\nИндексы: %d %d\n", index[0], index[1]);
}

void Newton_polynomial(double matrix[MAX_LEN][MAX_LEN], int row, int n, int index[2], double x)
{
    puts("");
    double result = matrix[1][index[0]], current = 1;
    // printf("result = %f\n", result);
    // printf("%lf ", matrix[0][0]);
    // printf("%lf ", matrix[0][1]);
    // printf("%lf ", matrix[0][2]);
    // printf("%lf \n", matrix[0][3]);

    for (int i = 0; i < n; i++)
    {
        // printf("%lf * %lf\n", matrix[index[0] + i][0], matrix[index[0]][index[0] + i + 1]);
        current *= (x - matrix[index[0] + i][0]);
        printf("%lf \n", current);

        result += current * matrix[index[0]][index[0] + i + 1];
    }
    printf("result = %f\n", result);
}