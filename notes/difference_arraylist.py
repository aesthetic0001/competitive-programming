n = 5
diff = [0 for i in range(n)]

# an update to range [l, r] (non inclusive)
def update(l, r, k):
    diff[l] += k
    diff[r] -= k

def compute():
    for i in range(1, n):
        diff[i] += diff[i - 1]

print(diff)
update(1, 3, 1)
compute()
print(diff)
