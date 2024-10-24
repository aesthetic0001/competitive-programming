import math
import random

# NOTE TO SELF: DO NOT USE e9 notation, just put the number otherwise python might tweak out
modulo = 1000000007
base = 31

def rolling_hash(target: str) -> list[int]:
    result = [0]
    power = 1
    hashresult = 0
    for char in target:
        mapping = ord(char) - ord('a') + 1
        mapping *= power
        mapping %= modulo
        power *= base
        power %= modulo
        hashresult += mapping
        hashresult %= modulo
        result.append(hashresult);

    return result

# runs until one part of the exponent is 0, other part would be the answer
def modpow(base: int, exponent: int) -> int:
    if exponent == 0:
        return 1
    ans = modpow(base * base % modulo, math.floor(exponent / 2))
    if exponent % 2 == 1:
        ans *= base
        ans %= modulo
    return ans

def fast_substr(target: list[int], start: int, end: int) -> int:
    # note that if start is also 1
    delta = target[end + 1] - target[start]
    offset = modpow(base, start)
    inverse = modpow(offset, modulo - 2)
    return delta * inverse % modulo

answer = rolling_hash("abc")
substr = fast_substr(answer, 1, 2)
comparison = rolling_hash("bc")[2]

print(substr)
print(comparison)

# test begin

def test():
    randstr = ""
    for _ in range(26):
        randstr += chr(random.randint(0, 25) + ord('a'))

    l = random.randint(0, 25)
    r = random.randint(l, 25)

    full = rolling_hash(randstr)
    baseline = rolling_hash(randstr[l:r + 1])[r - l + 1]
    fasthash = fast_substr(full, l, r)

    assert baseline == fasthash

# testing 100 cases of fasthash
print("Testing 100 cases of fasthash")
for i in range(100):
    test()

print("Fasthash passed!")
