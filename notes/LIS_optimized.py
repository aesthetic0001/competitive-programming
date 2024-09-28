import bisect

inf = 999999999999999

target = [8, 3, 4, 6, 5, 2, 0, 7, 9, 1]

# define lis_data: index l value v: represents the smallest last number v in a LIS of length l
lis_data = [inf for _ in range(len(target) + 1)]
lis_data[0] = -inf

for t in target:
    idx = bisect.bisect_right(lis_data, t)
    if t > lis_data[idx - 1]:
        lis_data[idx] = t

print(lis_data)

