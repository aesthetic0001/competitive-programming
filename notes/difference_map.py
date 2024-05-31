# implemented for 2spooky4me
import sys

input = sys.stdin.readline
print = sys.stdout.write

[N, L, S] = [int(x) for x in input().rstrip().split()]

diff = []

for i in range(N):
    [a, b, s] = [int(x) for x in input().rstrip().split()]
    diff.append((a, s))
    diff.append((b + 1, -s))

diff.sort()

if diff[-1][0] != L:
    diff.append((L, 0))

total_s = 0
start = 0
ans = 0

for d in diff:
    [i, s] = d
    if total_s < S:
        ans += i - start
    total_s += s
    start = i

print(str(ans))
