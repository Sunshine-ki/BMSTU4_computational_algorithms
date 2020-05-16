def LeftSide(y, h):
    list_result = list()
    for i in range(len(y)):
        if not i:
            list_result.append("-")
        else:
            list_result.append(((y[i] - y[i - 1]) / h))
    return list_result


def CenterDiff(y, h):
    list_result = list()
    for i in range(len(y)):
        if not i or i == len(y) - 1:
            list_result.append("-")
        else:
            list_result.append((y[i + 1] - y[i - 1]) / (2 * h))
    return list_result


def RungeLeft(y, h):
    list_result = list()
    for i in range(0, len(y)):
        if i < 2:
            list_result.append("-")
        else:
            list_result.append(2 * ((y[i] - y[i - 1]) / h) -
                               ((y[i] - y[i - 2]) / (2 * h)))

    return list_result


def Alignment(x, y, h):
    list_result = list()
    for i in range(0, len(y)):
        if i > len(y) - 2:
            list_result.append("-")
        else:
            list_result.append((1 / y[i + 1] - 1 / y[i]) / (1 /
                                x[i + 1] - 1 / x[i]) * y[i]**2 / x[i]**2)

    return list_result


def SecondDiff(y, h):
    list_result = list()
    for i in range(0, len(y)):
        if not i or i > len(y) - 2:
            list_result.append("-")
        else:
            list_result.append((y[i - 1] - 2 * y[i] +
                                y[i + 1]) / h ** 2)

    return list_result


def PrintResult(lst):
    for i in range(len(lst)):
        if lst[i] != "-":
            print("{:5.3f}".format(lst[i]), end=" ")
        else:
            print("{:<5}".format("-"), end=" ")
    print()


def main():
    h = 1
    x = [i for i in range(1, 7)]
    y = [0.571, 0.889, 1.091, 1.231, 1.333, 1.412]

    left_side = LeftSide(y, h)
    center = CenterDiff(y, h)
    runge_left = RungeLeft(y, h)
    alignment = Alignment(x, y, h)
    second_diff = SecondDiff(y, h)

    for i in [x, y, left_side, center, runge_left, alignment, second_diff]:
        PrintResult(i)


if __name__ == "__main__":
    main()
