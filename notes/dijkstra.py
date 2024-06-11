import queue

# (weight, node)
graph = {
    1: [(1, 2), (4, 3)],
    2: [(1, 1), (2, 3)],
    3: [(4, 1), (2, 2), (1, 4)],
    4: [(1, 3)]
}

def dijkstra(u, v):
    n = len(graph)
    d = [9999999 for _ in range(n + 1)]
    d[u] = 0
    pq = queue.PriorityQueue()
    pq.put((0, u))

    while not pq.empty():
        (dist, node) = pq.get()

        dist *= -1

        if dist > d[node]:
            continue

        for (l, other) in graph[node]:
            if d[other] > dist + l:
                d[other] = dist + l
                pq.put((-d[other], other))

    print(d)

    return d[v]

print(dijkstra(1, 4))
