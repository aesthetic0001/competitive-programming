import queue

graph = [
        [1, 3, 4],
        [2, 3],
        [],
        [4],
        []
]

ans = [None for i in range(len(graph))]
inbound = [0 for i in range(len(graph))]
vertices = 5
ct = 0

for nodes in graph:
    for neighbor in nodes:
        inbound[neighbor] += 1

q = queue.Queue()


for i in range(len(inbound)):
    if inbound[i] == 0:
        q.put(i)

while not q.empty():
    front = q.get()
    ans[ct] = front
    ct += 1

    for adj in graph[front]:
        inbound[adj] -= 1
        if inbound[adj] == 0:
            q.put(adj)

if not ct == vertices - 1:
    print("Graph is either cyclic or bidirectional")

print(ans)
