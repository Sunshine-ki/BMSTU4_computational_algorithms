import numpy as np

FILE_NAME = "../table/table3.txt"


def read_file():
    f = open(FILE_NAME)

    x, y, ro = list(), list(), list()

    for line in f:
        line = line.split(" ")
        x.append(float(line[0]))
        y.append(float(line[1]))
        ro.append(float(line[2]))

    f.close()
    return np.array(x), np.array(y), np.array(ro)
