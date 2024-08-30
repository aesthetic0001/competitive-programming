original = [1, 2, 3, 4, 5, 6, 7, 8]

# one indexed for simplicity's sake
fenwick = [0 for _ in range(len(original) + 1)]

# fenwick functions
def query(idx):
    ans = 0
    while idx > 0:
        ans += fenwick[idx]
        idx -= (idx & -idx)
    return ans

def update(idx, delta):
    while idx < len(fenwick):
        fenwick[idx] += delta
        idx += (idx & -idx)

def sum(l, r):
    return query(r) - query(l - 1)

# O(NlogN) initialization method
# for i in range(len(original)):
#    update(i + 1, original[i])

# O(N) initialization method
for i in range(len(original)):
    fenwick[i + 1] += original[i]
    if i + 1 + ((i + 1) & -(i + 1)) < len(fenwick):
        fenwick[i + 1 + ((i + 1) & -(i + 1))] += fenwick[i + 1]

print(sum(3, 4))
