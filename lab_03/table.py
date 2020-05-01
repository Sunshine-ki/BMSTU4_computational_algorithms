import numpy as np


def f(x):
    return x * x


def values():
    print("Заполнение таблицы!\n\
Введите начальное, конечное значение и шаг:")

    start, stop, step = map(float, input().split())
    x_values = np.arange(start, stop + 0.1, step)
    y_values = [f(x) for x in x_values]

    return x_values, y_values


def print_table(x_values, y_values):
    print(" {:^10} {:^10}".format("X", "Y"))
    for i in range(len(x_values)):
        print("|{:^10} |{:^10}|".format(
            round(x_values[i], 4), round(y_values[i], 4)))
