out_file = open('sample.out', 'w')

def print(k):
    out_file.write(str(k) + '\n')

with open('sample.in') as f:
    f = f.readlines()
    for line in f:
        print(" ".join(line.split()[0:2]))
