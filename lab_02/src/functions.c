#include "functions.h"
#include "matrix_func.h"
#include "colors.h"

// Функция ищет (по заданному х ) интервал, в который попадает х
// И записваеь индексы узлов (близкиких к х (кол-во n + 1)) в index .
int find_insert(double matrix[MAX_LEN][MAX_LEN], int row, double x, int index[2], int n)
{
    index[0] = 0;
    index[1] = 0;
    if (n >= row)
    {
        index[0] = 1;
        index[1] = row - 1;
        return OK;
    }
    // a и b - кол-во узлов, которые будут прибавляться к найденному интервалу.
    // k - итерационная переменная.
    int a, b, k;

    // Начинаем цикл по первому ряду(там записаны х-ы).
    for (int i = 1; i < row - 1; i++)
    {
        // Ищем интервал, в который попадает х.
        if (matrix[i][0] <= x && x <= matrix[i + 1][0] || matrix[i][0] >= x && x >= matrix[i + 1][0])
        {
            // Проверяем, имеем ли мы данный "y" уже в таблице.
            if (fabs(x - matrix[i][0]) < EPS)
            {
                return FOUND;
            }
            else if (fabs(x - matrix[i + 1][0]) < EPS)
            {
                return FOUND;
            }
            // Если не имеем, то нам нужно, чтобы узлов было (n + 1)
            // Тода интервал должен увеличиться с верху и снизу
            // На заданное ниже значение.
            a = b = (n - 1) / 2;
            // Если (n + 1) нечетное, то увеличиваем одно из чисел.
            if ((n - 1) % 2)
                a++;

            // Присваиваем найденный интервал и прибавляем кол-во узлов a и b.
            index[0] = i - a;
            index[1] = i + b + 1;

            // Если у нас интервал стал меньше нуля
            // (Такого быть не может, птому что в матрице индексация больше 0),
            // То нижняя граница становится равная 0,
            // А верхней прибавляется то значение, которое не влезло в нижний интервал.
            if (index[0] <= 0)
            {
                index[1] += -1 * index[0];
                index[0] = 1;
            }
            // Еслиже иначе, у нас интервал вышел за пределы
            // (Стал больше, чем у нас имеется значений),
            // То мы верхней границе границе присваиваем максимальное значение,
            // (То есть кол-во рядов), а к нижней прибавляем то, что не влезло в верхнюю.
            else if (index[1] >= row)
            {
                index[0] -= index[1] - (row);
                index[1] = row - 1;
            }
            return OK;
        }
    }

    return ERROR_FIND;
}

// Функция вычисляет оставшиеся столбы (Т.е. находит коэффициенты)
void func(double matrix[MAX_LEN][MAX_LEN], int m, int index[2])
{
    // m - Это степень полинома. Столбцов в матрице m + 2.
    // Т.к. 2-а первых столбца это x и y.
    m += 2;

    for (int j = 2, k = 1; j < m; j++, k++)
    {
        for (int i = index[0]; i < index[1] - 1; i++)
        {
            // Вычисляем значения, по формуле разделённой разности.
            matrix[i][j] = (matrix[i][j - 1] - matrix[i + 1][j - 1]) / (matrix[i][0] - matrix[i + k][0]);
        }
        // Сужаем нижнюю границу, т.к. мы вычисляем через разность двух элементов,
        // То в каждом следующем столбце у нас будет на 1 элемент меньше.
        index[1]--;
    }
}

// Строим полином Ньютона и вычисляем при заданном х.
double newton_polynomial(double matrix[MAX_LEN][MAX_LEN], int n, int index[2], double x)
{
    // puts("");
    // Результату присваиваем y0. Current - это текущий член суммы.
    double result = matrix[index[0]][1], current = 1;

    for (int i = 0; i < n; i++)
    {

        // Current умножаем на x - следующий x.
        // Т.е. итерируясь первый раз current = (х - х0).
        // Второй раз current = (х - х0) * (х - х1). и тд...
        current *= (x - matrix[index[0] + i][0]);

        // Результату каждый раз прибавляется current и y(x0, ... , xi).
        result += current * matrix[index[0]][i + 2];
    }

    return result;
}

double f(double x, double matrix[MAX_LEN][MAX_LEN], int row, int n, int index[2])
{
    // int err = find_insert(matrix, row, x, index, n);
    func(matrix, n, index);
    double result = newton_polynomial(matrix, n, index, x);

    return result;
}

double bilinear_interpolation(double matrix[MAX_LEN][MAX_LEN], int size, double x, double y, int nx, int ny)
{
    int index_x[2], index_y[2];
    double result;
    double current_matrix[MAX_LEN][MAX_LEN], matrix_x[MAX_LEN][MAX_LEN];
    int size_current = 0;
    int index_current[2] = {0, 0};

    int err = find_insert(matrix, size, x, index_x, nx);
    if (err == FOUND)
    {
        printf("Данное значение имеется в таблице\n");
        return ERROR;
    }
    else if (err == ERROR_FIND)
    {
        printf("Значение не найдено\n");
        return ERROR;
    }

    err = find_insert(matrix, size, y, index_y, ny);
    if (err == FOUND)
    {
        printf("Данное значение имеется в таблице\n");
        return ERROR;
    }
    else if (err == ERROR_FIND)
    {
        printf("Значение не найдено\n");
        return ERROR;
    }

    size_current = index_y[1] - index_y[0] + 1;

    // printf("\nindex (for x)= %d %d\n", index_x[0], index_x[1]);
    // printf("index (for y)= %d %d\n", index_y[0], index_y[1]);

    // printf("size_current (for y)= %d\n\n", size_current);

    for (int j = index_x[0], t = 0; j <= index_x[1]; j++, t++)
    {
        index_current[1] = size_current;
        for (int i = index_y[0], k = 0; i <= index_y[1]; i++, k++)
        {
            current_matrix[k][0] = matrix[i][0];
            current_matrix[k][1] = matrix[i][j];
        }
        matrix_x[t][0] = matrix[j][0];
        matrix_x[t][1] = f(x, current_matrix, ny, size_current, index_current);
    }
    size_current = index_x[1] - index_x[0] + 1;
    index_current[1] = size_current;
    result = f(y, matrix_x, size_current, nx, index_current);

    printf("Результат = %lf\n", result);
    // printf("Руальный результат: %lf\n", FUNC(x, y));

    // printf("\nMATRIX_X:\n");
    // print_matrix(stdout, matrix_x, size, size);
    // printf("\n");

    return result;
}