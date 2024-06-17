MAX = 5
parent = [None for i in range(MAX)]
size = [0 for i in range(MAX)]

# create a new disconnected component
def make_set(v):
    parent[v] = v
    size[v] = 1

def query(v):
    if parent[v] == v:
        return v
    parent[v] = query(parent[v])
    return parent[v]

def join_set(u, v):
    a = query(u)
    b = query(v)

    # belongs to different sets, we can indeed connect them
    if a != b:
        # we attach the tree with the lower rank/size to the one with the bigger rank/size.
        if size[a] >= size[b]:
            print(f"{a} is new parent of {b}")
            size[a] += size[b]
            parent[b] = a
        else:
            print(f"{b} is new parent of {a}")
            size[b] += size[a]
            parent[a] = b

for i in range(1, 5):
    make_set(i)

join_set(1, 2)
join_set(3, 4)
join_set(1, 3)

print(size[1:5])
print(parent[1:5])
