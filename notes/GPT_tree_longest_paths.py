from collections import defaultdict

def find_longest_paths(n, edges):
    tree = defaultdict(list)
    for u, v in edges:
        tree[u].append(v)
        tree[v].append(u)
    
    max_length1 = [0] * (n + 1)
    max_length2 = [0] * (n + 1)
    result = [0] * (n + 1)
    
    def dfs1(node, parent):
        for child in tree[node]:
            if child == parent:
                continue
            dfs1(child, node)
            length = max_length1[child] + 1
            if length > max_length1[node]:
                max_length2[node] = max_length1[node]
                max_length1[node] = length
            elif length > max_length2[node]:
                max_length2[node] = length
    
    def dfs2(node, parent):
        for child in tree[node]:
            if child == parent:
                continue
            if max_length1[child] + 1 == max_length1[node]:
                result[child] = max(max_length2[node] + 1, result[node] + 1)
            else:
                result[child] = max(max_length1[node] + 1, result[node] + 1)
            dfs2(child, node)
    
    dfs1(1, -1)
    result[1] = max_length1[1]
    dfs2(1, -1)
    print(result)
    return result[1:]

# Example usage:
n = 6  # Number of nodes
edges = [(1,2),(1,3),(1,4),(2,5),(2,6)]
print(find_longest_paths(n, edges))

