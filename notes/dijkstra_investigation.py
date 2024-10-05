import queue

# (weight, node)
graph = {
    1: [(1, 2), (100, 3)],
    2: [],
    3: [(-100, 2)]
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

print(dijkstra(1, 3))
