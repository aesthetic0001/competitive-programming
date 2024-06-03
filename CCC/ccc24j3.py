N = int(input())

scores_counter = {}
scores_list = []

for i in range(N):
    k = int(input())
    if k in scores_counter:
        scores_counter[k] += 1
        continue
    scores_counter[k] = 1
    scores_list.append(k)

scores_list.sort(reverse=True)

print(f"{scores_list[2]} {scores_counter.get(scores_list[2])}")
