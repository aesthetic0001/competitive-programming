# Given an n × n grid whose each square is either black (1) or white (0),
# calculate the number of subgrids whose all corners are black.

grid = [
    [0, 1, 0, 0, 1],
    [0, 1, 1, 0, 0],
    [1, 0, 0, 0, 0],
    [0, 1, 1, 0, 1],
    [0, 0, 0, 0, 0]
]

precomp = []

for i in range(5):
    res = ""
    for j in range(5):
        res += str(grid[i][j])
    precomp.append(int(res, 2))

ans = 0

# find the number of filled columns for each row, then use N choose 2 to find valid subgrids in the N columns
for i in range(4):
    for j in range(i + 1, 5):
        count = (precomp[i] & precomp[j]).bit_count()
        ans += (count * (count - 1)) / 2

print(int(ans))
