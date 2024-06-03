arr = [1, 2, 3, 4, 5]
psa = [0 for i in range(len(arr) + 1)]

for i in range(1, len(arr) + 1):
    psa[i] = arr[i - 1] + psa[i - 1]

# inclusive sum
def sum(l, r):
    return psa[r + 1] - psa[l]

# prints 3
print(sum(0, 1))
