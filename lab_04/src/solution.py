from numpy import zeros, linalg, sum, arange, array

STEP = 0.05


def create_list_points(x_start, x_end, coefficients):
    x = arange(x_start, x_end + 0.1, STEP)
    y = zeros(len(x))

    for i in range(len(coefficients)):
        y += coefficients[i] * x**i

    return x, y


def root_mean_square(list_x, list_y, list_ro, n):
    # Матрица коэффициентов (Т.е. (x^k, x^m))
    matrix = zeros((n + 1, n + 1))
    # Массив значений (То что стоит после равно, т.е. (y, x^k))
    list_value = zeros(n + 1)

    for i in range(n + 1):
        for j in range(i, n + 1):
            matrix[i][j] = matrix[j][i] = sum(list_ro * list_x**(i + j))

    for i in range(n + 1):
        list_value[i] = sum(list_ro * list_y * list_x**i)

    # Возвращаем коэффициенты полинома (ak).
    return linalg.solve(matrix, list_value)
