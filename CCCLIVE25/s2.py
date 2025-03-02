import sys
input = sys.stdin.readline

input_str = input()
n=int(input())

to_parse=""
total=0
alpha={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

chars=[]
prev_char_parse=""

for c in input_str:
    if c in alpha:
        if len(to_parse)>0:
            total+=int(to_parse)
            chars.append((prev_char_parse, int(to_parse)))
            to_parse=""
        prev_char_parse=c
    else:
        to_parse+=c

if len(to_parse)>0:
    total+=int(to_parse)
    chars.append((prev_char_parse, int(to_parse)))
    to_parse=""

times = n % total

at=0
prev_c = chars[0][0]

for (char, ct) in chars:
    if at > times:
        break
    at+=ct
    prev_c=char

print(prev_c)
