import heapq

# (other, weight)
graph = {
        1: [(2, 3), (3, 5)],
        2: [(1, 3), (3, 2)],
        3: [(1, 5), (2, 2)]
        }

vis = [False for i in range(4)]
pq = []
mst = []

for (k, edges) in enumerate(graph.values()):
    for i in range(len(edges)):
        graph[k + 1][i] = (edges[i][1], edges[i][0])

heapq.heappush(pq, (0, 1, 1))

while len(pq) > 0:
    (weight, origin, top) = heapq.heappop(pq)

    if vis[top]:
        continue

    vis[top] = True
    print(f"vis {top}")

    if origin != top:
        mst.append((origin, top))

    for adj in graph[top]:
        if not vis[adj[1]]:
            heapq.heappush(pq, (adj[0], top, adj[1]))

print(mst)
