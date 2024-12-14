edges = [
[(1,7),(3,2),(2,3)],
[],
[],
[(1,4)]
]

inf = 99999999
maxN = 4

dis = [[] for _ in range(maxN)]


for k in range(maxN):
    for i in range(maxN):
        for j in range(maxN):
            if dis[i][k] < inf and dis[k][j] < inf:
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j])

print(dis)
