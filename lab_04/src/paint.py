import matplotlib.pyplot as plt


def show_graph(x_points, y_points, x_list, y_list):
    # Построение графика.
    plt.title("График")  # Заголовок.
    plt.xlabel("x")      # Ось абсцисс.
    plt.ylabel("y")      # Ось ординат.
    plt.grid()           # Включение отображение сетки.

    # Отразим точки из файла.
    plt.scatter(x_points, y_points)
    plt.plot(x_list, y_list)

    plt.show()
