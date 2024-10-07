import queue

inf = 9999999999
# originally was edges = [(1, 2, 1), (2, 3, 1), (3, 4, 2), (2, 4, -3)]
adj = [
    [],
    [(2, 1)],
    [(3, 1), (4, -3)],
    [(4, 2)],
    []
]
ct = [0 for _ in range(5)]
dis = [inf for _ in range(5)]
queued = [False for _ in range(5)]
q = queue.Queue()

dis[1] = 0
q.put(1)

while not q.empty():
    top = q.get();
    queued[top] = False

    print(f"vis {top}")

    for [adjacent, weight] in adj[top]:
        if dis[adjacent] > dis[top] + weight:
            dis[adjacent] = dis[top] + weight
            if not queued[adjacent]:
                q.put(adjacent)
                queued[adjacent] = True
                ct[adjacent] += 1
                if ct[adjacent] > 4:
                    print("Negative Cycle")
                    break

print(dis)
