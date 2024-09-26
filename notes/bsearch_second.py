import math

# find the first true value returned by monotonic_fn
def monotonic_fn(x, n):
    return pow(x, 2) >= n

def sqrt_bsearch(n):
    l = 0
    r = n
    arr = [monotonic_fn(x, n) for x in range(n + 1)]
    print("monotonic fn output:", arr)
    while (r > l):
        # midpoint is the best guess
        best_guess = math.floor((l + r) / 2)
        print(f"l: {l}, r: {r}, guess: {best_guess}")

        if monotonic_fn(best_guess, n):
            print("guess too high, upper bound should be decreased")
            r = best_guess
        else:
            print("guess too low, lower bound should be increased")
            l = best_guess + 1
    return l

print(sqrt_bsearch(4))

