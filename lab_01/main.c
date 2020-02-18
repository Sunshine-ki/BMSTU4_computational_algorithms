#include <stdio.h>

#include "functions.h"
#include "matrix_func.h"
#include "define.h"
#include "colors.h"

// table - y = x.
// table2 - y = cos(pi/2x) (Из лекции). + print(matrix)!!!
// table3 - cos(x)
// table4 - cos(x) reverse.
// table5 - cos(x) // Для метода половинного деления.
// table6 - x - 7 (4, 9, 0.35) (x и y местами поменялись). (Обратная интерполяция)
int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], MODE_READ);
    double matrix[MAX_LEN][MAX_LEN], x;
    int n;
    int index[2];

    yellow();
    printf("Введите степень: ");
    int rc = scanf("%d", &n);
    if (!rc)
    {
        printf("Некорректный ввод.\n");
        return ERROR_INPUT;
    }
    printf("Введите x: ");
    rc = scanf("%lf", &x);
    if (!rc)
    {
        printf("Некорректный ввод.\n");
        return ERROR_INPUT;
    }
    white();

    int row = fill_matrix(f, matrix, n);
    int err = find_insert(matrix, row, x, index, n);

    if (err == FOUND)
    {
        red();
        printf("Данный корень имеется в таблице!\n");
        white();
        return 0;
    }
    else if (err == ERROR_FIND)
    {
        red();
        printf("Не найдено значение.");
        white();
        return err;
    }
    func(matrix, row, n, index);

    double result = Newton_polynomial(matrix, row, n, index, x);

    green();
    printf("Результат интерполяции: y = %lf\n", result);
    // printf("Результат функции (Реальный) %lf\n", FUNC(x));
    // printf("Погрешность: %lf\n", fabs(result - FUNC(x)));
    white();

    print_matrix(stdout, matrix, row, n);

    int answer;
    yellow();
    printf("Желаете найти корень методом половинного деления? (1 - Да / 0 - Нет) ");
    scanf("%d", &answer);
    if (!answer)
        return OK;

    // Метод половинного деления
    green();
    double a, b;
    printf("Введите a и b: ");
    scanf("%lf %lf", &a, &b);
    double res = method_division(a, b, matrix, row, n, index);

    white();
    fclose(f);
    return OK;
}