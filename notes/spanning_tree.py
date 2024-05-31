tree = {
    1: [2, 3, 4],
    2: [1, 3],
    3: [1, 2],
    4: [1]
}

spanning_tree = {}

def dfs(vertex, origin = None):
    if vertex in spanning_tree:
        return

    spanning_tree[vertex] = []

    if origin != None:
        # bidirectional
        spanning_tree[origin].append(vertex)
        spanning_tree[vertex].append(origin)


    for v in tree[vertex]:
        dfs(v, vertex)

dfs(1)

for u in spanning_tree:
    for v in spanning_tree[u]:
        print(f"{u} {v}")
