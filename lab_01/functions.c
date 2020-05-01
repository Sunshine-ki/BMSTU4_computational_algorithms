#include "headers/functions.h"
#include "matrix_func.h"

// Функция ищет (по заданному х ) интервал, в который попадает х
// И записваеь индексы узлов (близкиких к х (кол-во n + 1)) в index .
int find_insert(double matrix[MAX_LEN][MAX_LEN], int row, double x, int index[2], int n)
{
    index[0] = 0;
    index[1] = 0;
    if (n >= row)
    {
        index[0] = 0;
        index[1] = row - 1;
        return OK;
    }
    // a и b - кол-во узлов, которые будут прибавляться к найденному интервалу.
    // k - итерационная переменная.
    int a, b, k;

    // Начинаем цикл по первому ряду(там записаны х-ы).
    for (int i = 0; i < row - 1; i++)
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
            if (index[0] < 0)
            {
                index[1] += -1 * index[0];
                index[0] = 0;
            }
            // Еслиже иначе, у нас интервал вышел за пределы
            // (Стал больше, чем у нас имеется значений),
            // То мы верхней границе границе присваиваем максимальное значение,
            // (То есть кол-во рядов), а к нижней прибавляем то, что не влезло в верхнюю.
            else if (index[1] >= row)
            {
                index[0] -= index[1] - (row - 1);
                index[1] = row - 1;
            }
            return OK;
        }
    }

    return ERROR_FIND;
}

// Функция вычисляет оставшиеся столбы (Т.е. находит коэффициенты)
void func(double matrix[MAX_LEN][MAX_LEN], int n, int m, int index[2])
{
    // m - Это степень полинома. Столбцов в матрице m + 2.
    // Т.к. 2-а первых столбца это x и y.
    m += 2;

    for (int j = 2, k = 1; j < m; j++, k++)
    {
        for (int i = index[0]; i < index[1]; i++)
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
double Newton_polynomial(double matrix[MAX_LEN][MAX_LEN], int row, int n, int index[2], double x)
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
    int err = find_insert(matrix, row, x, index, n);
    func(matrix, row, n, index);
    double result = Newton_polynomial(matrix, row, n, index, x);

    return result;
}

double method_division(double a, double b, double matrix[MAX_LEN][MAX_LEN], int row, int n, int index[2])
{
    if (fabs(f(a, matrix, row, n, index)) <= EPS)
    {
        printf("result = %lf %lf\n", a, f(a, matrix, row, n, index));
        return a;
    }
    else if (fabs(f(b, matrix, row, n, index)) <= EPS)
    {
        printf("result = %lf %lf\n", b, f(b, matrix, row, n, index));
        return b;
    }
    if (f(a, matrix, row, n, index) * f(b, matrix, row, n, index) > 0)
    {
        printf("Нет корня\n");
        return 0;
    }
    else if (fabs(a - b) < EPS)
    {
        printf("Не верные а и b\n");
        return 0;
    }

    double x, c = (a + b) / 2.0;

    while (fabs(a - b) >= fabs(c) * EPS + EPS)
    {
        if (f(a, matrix, row, n, index) * f(c, matrix, row, n, index) <= 0)
            b = c;
        else
            a = c;

        c = (a + b) / 2.0;
    }

    x = (a + b) / 2;
    printf("result = %lf\n", x); //, f(x, matrix, row, n, index));
    return x;
}