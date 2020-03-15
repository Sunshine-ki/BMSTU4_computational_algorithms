

def find_min(x_values, x):
    for i in range(len(x_values) - 1):
        if x > x_values[i] and x < x_values[i + 1]:
            return i


def interpolation(x_values, y_values, x):
    n = len(x_values)
    index = find_min(x_values, x)
    if not index:
        print("Значение либо имеется в таблице, \
либо выходит за её пределы.\n")
        return

    h = [0]
    for i in range(1, n):
        h.append(x_values[i] - x_values[i - 1])

    A = [0, 0]
    for i in range(2, n):
        A.append(h[i - 1])

    B = [0, 0]
    for i in range(2, n):
        B.append(-2 * (h[i - 1] + h[i]))

    D = [0, 0]
    for i in range(2, n):
        D.append(h[i])

    F = [0, 0]
    for i in range(2, n):
        F.append(-3 * ((y_values[i] - y_values[i - 1]) / h[i] -
                       (y_values[i - 1] - y_values[i - 2]) / h[i - 1]))

    # Прямой ход.
    ξ = [0 for i in range(n + 1)]
    η = [0 for i in range(n + 1)]
    for i in range(2, n):
        ξ[i + 1] = D[i] / (B[i] - A[i] * ξ[i])
        η[i + 1] = (A[i] * η[i] + F[i]) / (B[i] - A[i] * ξ[i])

    # print(" h = ", h, '\n A  = ', A, '\n B = ', B, '\n D = ', D, '\n F = ', F)
    # print("\nξ = ", ξ)
    # print("\nη = ", η)

    # Обратный ход.
    c = [0 for i in range(n + 1)]
    for i in range(n - 2, -1, -1):
        c[i] = ξ[i + 1] * c[i + 1] + η[i + 1]

    a = [0]
    for i in range(1, n):
        a.append(y_values[i - 1])

    b = [0]
    for i in range(1, n):
        b.append((y_values[i] - y_values[i - 1]) /
                 h[i] - h[i] / 3 * (c[i + 1] + 2 * c[i]))

    d = [0]
    for i in range(1, n):
        d.append((c[i + 1] - c[i]) / (3 * h[i]))

    # print(" a = ", a, '\n b = ', b, '\n c = ', c, '\nd = ', d)
    # print(index)

    diff = x - x_values[index - 1]
    return a[index] + b[index] * (diff) + c[index] * ((diff) ** 2) + d[index] * ((diff) ** 3)


#     index = find_min(x_values, x)

#     if not index:
#         print("Значение либо имеется в таблице, \
# либо выходит за её пределы.\n")
#         return
#     print(index)
#     h1 = x_values[index] - x_values[index - 1]
#     h2 = x_values[index + 1] - x_values[index]

#     A = h1
#     B = -2.0 * (h1 + h2)
#     D = h2
#     F = -3 * ((y_values[index + 1] - y_values[index]) / h2 -
#               (y_values[index] - y_values[index - 1]) / h1)

#     ξ = D / (B - A * ξ[i])

#     print(A, B, D, F)
