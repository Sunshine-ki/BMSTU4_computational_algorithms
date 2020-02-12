#include "headers/functions.h"

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
    // Обнуляет оставшиеся значения.
    for (int i = 0; i < row; i++)
    {
        for (int j = 2; j < n; j++)
            matrix[i][j] = 0;
    }

    return row;
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

// Функция ищет (по заданному х ) интервал, в который попадает х
// И выбирает узлы,близкие к х (кол-во n + 1).
int find_insert(double matrix[MAX_LEN][MAX_LEN], int row, double x, int index[2], int n)
{
    // a и b - кол-во узлов, которые будут прибавляться к найденному интервалу.
    // k - итерационная переменная.
    int a, b, k;

    // Начинаем цикл по первому ряду(там записаны х-ы).
    for (int i = 0; i < row - 1; i++)
    {
        // Ищем интервал, в который попадает х.
        if (matrix[i][0] <= x && x <= matrix[i + 1][0] || matrix[i][0] >= x && x >= matrix[i + 1][0])
        {
            // Проверяем, имеем ли мы данный y уже в таблице.
            if (fabs(x - matrix[i][0]) < EPS)
            {
                printf("y = %lf", matrix[i][1]);
                return FOUND;
            }
            else if (fabs(x - matrix[i + 1][0]) < EPS)
            {
                printf("y = %lf", matrix[i + 1][1]);
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

            // printf("x = %lf x - matrix[i][0] = %lf %d\n", x, fabs(x - matrix[i + 1][0]), fabs(x - matrix[i + 1][0]) < EPS);
            // printf("Значения: %lf %lf\n", matrix[i][0], matrix[i + 1][0]);
            // printf("\nИндексы ДО: %d %d\n", i, i + 1);
            // printf("\na = %d b = %d\n", a, b);

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
            // printf("row = %d\n", row);
            printf("Индексы ПОСЛЕ: %d %d\n", index[0], index[1]);

            return OK;
        }
    }
    printf("Экстрополяция! (Выход за пределы)");
    return ERROR_FIND;
}

// Функция вычисляет оставшиеся столбы (Т.е. находит коэффициенты)
void func(double matrix[MAX_LEN][MAX_LEN], int n, int m, int index[2])
{
    // m - Это степень полинома. Столбцов в матрице m + 2.
    // Т.к. 2-а первых столбца это x и y.
    m += 2;
    // printf("\nИндексы: %d %d\n", index[0], index[1]);

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
    // printf("\nИндексы: %d %d\n", index[0], index[1]);
}

// Строим полином Ньютона и вычисляем при заданном х.
double Newton_polynomial(double matrix[MAX_LEN][MAX_LEN], int row, int n, int index[2], double x)
{
    puts("");
    // Результату присваиваем y0. Current - это текущий член суммы.
    double result = matrix[index[0]][1], current = 1;

    printf("Res (до) = %lf\n", result);

    for (int i = 0; i < n; i++)
    {
        // printf("index = %d\n ", index[0]);
        // printf("%lf * %lf\n", matrix[index[0] + i][0], matrix[index[0]][index[0] + i + 1]);
        // Current умножаем на x - следующий x.
        // Т.е. итерируясь первый раз current = (х - х0).
        // Второй раз current = (х - х0) * (х - х1). и тд...
        current *= (x - matrix[index[0] + i][0]);
        // printf("current = %lf * ", current);
        // printf("index = %d %d %lf\n ", index[0], i + 2, matrix[index[0]][i + 2]);

        // Результату каждый раз прибавляется current и y(x0, ... , xi).
        result += current * matrix[index[0]][i + 2];
    }
    printf("Res = %lf\n", result);

    return result;
}