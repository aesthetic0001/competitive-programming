# Given an n × n grid whose each square is either black (1) or white (0),
# calculate the number of subgrids whose all corners are black.

grid = [
    [0, 1, 0, 0, 1],
    [0, 1, 1, 0, 0],
    [1, 0, 0, 0, 0],
    [0, 1, 1, 0, 1],
    [0, 0, 0, 0, 0]
]

ans = 0

# find the number of filled columns for each row, then use N choose 2 to find valid subgrids in the N columns
for i in range(4):
    for j in range(i + 1, 5):
        count = 0
        for k in range(5):
            if grid[i][k] == 1 and grid[j][k] == 1:
                count += 1
        ans += (count * (count - 1)) / 2

print(int(ans))
