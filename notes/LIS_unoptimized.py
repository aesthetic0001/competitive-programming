inf = 999999999999999

target = [8, 3, 4, 6, 5, 2, 0, 7, 9, 1]

# define lis_data: index l value v: represents the smallest last number v in a LIS of length l
lis_data = [inf for _ in range(len(target) + 1)]
lis_data[0] = -inf

for t in target:
    for idx in range(1, len(target) + 1):
        # we can branch off of previous LIS if and only if it is a greater value AND should only branch off if it gives better result (smaller end value, giving more opportunity for larger branch)
        if t > lis_data[idx - 1] and lis_data[idx] > t:
            lis_data[idx] = t

print(lis_data)
