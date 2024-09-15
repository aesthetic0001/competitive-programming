graph = [
        [1, 3, 4],
        [2, 3],
        [],
        [4],
        []
        ]

vis = [False for i in range(len(graph))]
ans = []

def dfs(node):
    print(f"Vis {node}")
    vis[node] = True

    for adj in graph[node]:
        if not vis[node]:
            dfs(node)

    print(f"Exit {node}")

    ans.append(node)

for i in range(len(graph)):
    if not vis[i]:
        dfs(i)

print(ans)

ans.reverse()

print(ans)
