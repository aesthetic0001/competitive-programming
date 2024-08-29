x = 5

for i in range(31, -1, -1):
    if x & (1 << i) != 0:
        print(1, end="")
    else:
        print(0, end="")
