target = [8, 3, 4, 6, 5, 2, 0, 7, 9, 1]
compressed = []
BIT = [0 for _ in range(len(target) + 2)]

def update(idx, delta):
    while idx < len(BIT):
        BIT[idx] = delta
        idx += (idx & -idx)

def query(idx):
    ans = 0
    while idx > 0:
        ans = max(BIT[idx], ans)
        idx -= (idx & -idx)
    return ans

# we need to coordinate compress target
t_to_idx = {}

compressed = target.copy()
target.sort()

ctr = 1
for t in target:
    if not t in t_to_idx:
        t_to_idx[t] = ctr
        ctr += 1

for i in range(len(compressed)):
    compressed[i] = t_to_idx[compressed[i]]

print(compressed)

for v in compressed:
    prev = query(v - 1)
    print(f"v: {v}, best: {prev}")
    update(v, prev + 1)

print(BIT)
print(query(len(BIT) - 1))
