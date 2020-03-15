from table import *
from interpolation_spline import *


def main():
    x_values, y_values = values()

    print_table(x_values, y_values)

    x = float(input("Введите x: "))

    result = interpolation(x_values, y_values, x)
    if not result:
        return

    print("f({}) = {}".format(x, f(x)))
    print("interpolation_spline: {}".format(round(result, 4)))
    print("Error = {}".format(abs(round(f(x) - result, 4))))


if __name__ == "__main__":
    main()
