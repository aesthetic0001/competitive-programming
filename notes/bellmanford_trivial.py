inf = 9999999999
edges = [(1, 2, 1), (2, 3, 1), (3, 4, 2), (2, 4, -3)]
dis = [inf for i in range(5)]

# starting at 1
dis[1] = 0

while True:
    extended = False
    for [u, v, weight] in edges:
        # if this node is visitable (ie. the weight is not infinity)
        if dis[u] < inf and dis[v] > dis[u] + weight:
            dis[v] = dis[u] + weight
            extended = True

    if not extended:
        break

print(dis)
