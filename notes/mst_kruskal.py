import heapq

# disjoint set
parent = [0 for i in range(4)]
sz = [0 for i in range(4)]

def mk(v):
    parent[v] = v
    sz[v] = 1

def qu(v):
    if parent[v] == v:
        return v
    parent[v] = qu(parent[v])
    return parent[v]

def jn(a, b):
    pA = qu(a)
    pB = qu(b)

    if pA == pB:
        return False

    if sz[pA] >= sz[pB]:
        parent[pB] = pA
        sz[pA] += pB
    else:
        parent[pA] = pB
        sz[pB] += pA

    return True

# (other, weight)
graph = {
        1: [(2, 3), (3, 5)],
        2: [(1, 3), (3, 2)],
        3: [(1, 5), (2, 2)]
        }

pq = []
mst = []

for (k, edges) in enumerate(graph.values()):
    for i in range(len(edges)):
        heapq.heappush(pq, (edges[i][1], k + 1, edges[i][0]))

for i in range(1, 4):
    mk(i)

while len(pq) > 0 and len(mst) != len(graph) - 1:
    (weight, a, b) = heapq.heappop(pq)

    if jn(a, b):
        mst.append((a, b, weight))

print(mst)
