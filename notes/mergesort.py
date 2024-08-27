unsorted = [-3, 9, 2, 4, -2]

def merge_sort(unsorted):
    print("iter for", unsorted)
    if len(unsorted) == 1:
        print("reached root:", unsorted)
        return unsorted

    midpoint = len(unsorted) // 2

    sorted_left = merge_sort(unsorted[:midpoint])
    sorted_right = merge_sort(unsorted[midpoint:])

    print("merging: ", sorted_left, sorted_right)

    res = []
    i = j = 0

    while i < len(sorted_left) and j < len(sorted_right):
        if sorted_left[i] <= sorted_right[j]:
            res.append(sorted_left[i])
            i += 1
        else:
            res.append(sorted_right[j])
            j += 1

    print(i, j)

    if i != len(sorted_left):
        # already sorted, just need to append
        for k in range(i, len(sorted_left)):
            res.append(sorted_left[k])
    else:
        for k in range(j, len(sorted_right)):
            res.append(sorted_right[k])

    print("merge result:", res)

    return res


print(merge_sort(unsorted))
