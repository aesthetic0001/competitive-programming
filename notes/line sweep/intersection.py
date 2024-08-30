# O(NlogN) solution to the intersection problem

# input: x1 y1 x2 y2
vertical = [(3, 1), (3, 4)]
horizontal = [(1, 1), (4, 1), (2, 3), (5, 3)]

# program start
ans = 0

events = []
events.extend(vertical)
events.extend(horizontal)

events.sort(key=lambda x: x[0])

print(events)

# should reach up to max vertical height
# i will just hardcode for simplicity's sake
BIT = [0 for _ in range(5)]
active = set()

def query(idx):
    ct = 0
    while idx > 0:
        ct += BIT[idx]
        idx -= idx & -idx
    return ct

def update(idx, delta):
    while idx < len(BIT):
        BIT[idx] += delta
        idx += idx & -idx
    print(BIT)

def range_query(l, r):
    print("range query", l, r)
    print("query state", BIT)
    print(f"r: {query(r)} l: {query(l - 1)}")
    return query(r) - query(l - 1)

for i, (x, y) in enumerate(events):
    # print(x, y)
    if ((i - 1 >= 0 and events[i - 1][0] == x) or (i + 1 < len(events) and events[i + 1][0] == x)):
        # vertical line
        if i + 1 < len(events) and events[i + 1][0] == x:
            print("vertical")
            ans += range_query(min(events[i + 1][1], y), max(events[i + 1][1], y))
    else:
        # horizontal line
        if y in active:
            # inactive now
            print("horizontal end at", y)
            update(y, -1)
            active.remove(y)
        else:
            print("horizontal start at", y)
            update(y, 1)
            active.add(y)
print(ans)
