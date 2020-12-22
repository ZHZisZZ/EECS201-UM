import sys

if len(sys.argv) == 1:
    exit(1)

x = 1
while x < int(sys.argv[1]) + 1:
    print(x)
    x += 1

for x in range(1, int(sys.argv[1]) + 1):
    print(x)
