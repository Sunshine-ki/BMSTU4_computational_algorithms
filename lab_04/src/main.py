from functions_file import read_file
from solution import root_mean_square, create_list_points
from paint import show_graph


def main():
    x, y, ro = read_file()
    n = int(input("Введите степень: "))

    coefficients = root_mean_square(x, y, ro, n)
    x_list, y_list = create_list_points(x[0], x[-1], coefficients)
    show_graph(x, y, x_list, y_list)


if __name__ == "__main__":
    main()
