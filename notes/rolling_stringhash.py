def rolling_hash(target: str) -> int:
    modulo = 10e9 + 7
    base = 31
    power = 1
    hashresult = 0
    for char in target:
        mapping = ord(char) - ord('a') + 1
        mapping *= power
        mapping %= modulo
        power *= base
        power %= modulo
        hashresult += int(mapping)
        hashresult %= modulo
        hashresult = int(hashresult)

    return hashresult

print(rolling_hash("ab"))
