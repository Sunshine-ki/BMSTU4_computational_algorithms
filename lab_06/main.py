
# def functions(x):

def LeftSide(y, h):
	list_result = list()
	for i in range(len(y)):
		if not i:
			list_result.append("-")
		else:
			list_result.append(round(((y[i] - y[i - 1]) / h),4))
	return list_result

def CenterDiff(y, h):
	list_result = list()
	for i in range(len(y)):
		if not i or i == len(y) - 1:
			list_result.append("-")
		else:
			list_result.append(round((y[i + 1] - y[i - 1]) \
				/ (2 * h), 4))
	return list_result
	
def RungeCenter(y, h):
	list_result = list()
	n = len(y)
	p, r = 2, 2
		
	ksi_h = [(y[i + 1] - y[i - 1]) / (2*h) for i in range(2, n-2)]
	ksi_rh = [(y[i + r] - y[i - r]) / (2*h*r) for i in range(2, n-2)]
		
	for i in range(-2, n-2):
		if  i >= n - 4 or i < 0:
			list_result.append("-")
		else:
			list_result.append(round((ksi_h[i] + (ksi_h[i] - ksi_rh[i]) / (r**p - 1)), 4))

	return list_result


def print_result(text, lst):
	print("{:<15}".format(text), end = "")

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
	runge_center = RungeCenter(y, h)
	# alignment = Alignment(x, y)

	print(x, y, left_side, center,sep="\n")

	print_result("x", x)
	print_result("y", y)
	print_result("Left side", left_side)
	print_result("Center", center)
	print_result("Runge", runge_center)
	# print_result("Alignment", )




if __name__ == "__main__":
	main()

