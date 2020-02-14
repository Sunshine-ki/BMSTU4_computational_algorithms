#include <stdio.h>

#include "functions.h"
#include "define.h"
#include "colors.h"

// table - y = x.
// table2 - y = cos(pi/2x) (Из лекции).
// table3 - cos(x)
// table4 - cos(x) reverse.
// table5 - y = i * i + 8 * i + 12; (-2 и -6)
// table5 - y = i * i + 8 * i + 12; (-2 и -6) (reverse (y x))
int main(int argc, char *argv[])
{
    // FILE *f = fopen(argv[1], MODE_READ);
    // double matrix[MAX_LEN][MAX_LEN], x;
    // int n;
    // int index[2];

    // yellow();
    // printf("Введите степень: ");
    // int rc = scanf("%d", &n);
    // if (!rc)
    // {
    //     printf("Некорректный ввод.");
    //     return ERROR_INPUT;
    // }
    // printf("Введите x: ");
    // rc = scanf("%lf", &x);
    // if (!rc)
    // {
    //     printf("Некорректный ввод.");
    //     return ERROR_INPUT;
    // }

    // white();

    // int row = fill_matrix(f, matrix, n);
    // int err = find_insert(matrix, row, x, index, n);

    // if (err == FOUND)
    //     return 0;
    // else if (err == ERROR_FIND)
    // {
    //     return err;
    // }
    // func(matrix, row, n, index);

    // double result = Newton_polynomial(matrix, row, n, index, x);

    // green();
    // printf("Результат интерполяции: y = %lf\n", result);
    // printf("Результат функции (Реальный) %lf\n", FUNC(x));
    // printf("Погрешность: %lf\n", fabs(result - FUNC(x)));
    // white();

    // print_matrix(stdout, matrix, row, n);

    double a, b;
    printf("Введите a и b: ");
    scanf("%lf %lf", &a, &b);
    double res = method_division(a, b);

    // fclose(f);
    return OK;
}