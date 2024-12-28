import sys
input = sys.stdin.readline

N, F = map(int, input().split())

letters = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]

moos = set()
occurences = {}

def count_moos(s):
    for i in range(len(s) - 2):
        if s[i+1]==s[i+2] and s[i] != s[i+1]:
            moo = s[i] + s[i+1] + s[i+2]
            if moo in occurences:
                occurences[moo] += 1
            else:
                occurences[moo] = 1
            if occurences[moo] >= F:
                moos.add(moo)

def add_moo(moo):
    if moo in occurences:
        occurences[moo] += 1
    else:
        occurences[moo] = 1
    if occurences[moo] >= F:
        moos.add(moo)

def remove_moo(moo):
    occurences[moo] -= 1

s = input().strip()

count_moos(s)

# print(occurences)

for i in range(N):
    for j in range(len(letters)):
        letter = letters[j]
        extraneous = []
        add_back = []
        if i+2 < len(s):
            old_moo = s[i] + s[i+1] + s[i+2]
            if old_moo in occurences:
                remove_moo(old_moo)
                add_back.append(old_moo)

        if i-1 >= 0 and i+1 < len(s):
            old_moo = s[i-1] + s[i] + s[i+1]
            if old_moo in occurences:
                remove_moo(old_moo)
                add_back.append(old_moo)

        if i-2 >= 0:
            old_moo = s[i-2] + s[i-1] + s[i]
            if old_moo in occurences:
                remove_moo(old_moo)
                add_back.append(old_moo)

        if i+2 < len(s):
            new_moo = letter + s[i+1] + s[i+2]
            if letter != s[i+1] and s[i+1] == s[i+2]:
                add_moo(new_moo)
                extraneous.append(new_moo)

        if i-1 >= 0 and i+1 < len(s):
            new_moo = s[i-1] + letter + s[i+1]
            if letter == s[i+1] and s[i-1] != letter:
                add_moo(new_moo)
                extraneous.append(new_moo)

        if i-2 >= 0:
            new_moo = s[i-2] + s[i-1] + letter
            if letter == s[i-1] and s[i-2] != letter:
                add_moo(new_moo)
                extraneous.append(new_moo)

        for moo in extraneous:
            remove_moo(moo)
        for moo in add_back:
            add_moo(moo)

moos = sorted(list(moos))
print(len(moos))
for moo in moos:
    print(moo)
