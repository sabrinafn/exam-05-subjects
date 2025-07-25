#!/usr/bin/env python3
import sys
import random

if len(sys.argv) != 4:
    print("Usage: program x y density")
    sys.exit(1)

x = int(sys.argv[1])
y = int(sys.argv[2])
density = int(sys.argv[3])

print(f"{y} . o x")
for i in range(y):
    for j in range(x):
        if random.randint(0, y * 2 - 1) < density:
            print("o", end="")
        else:
            print(".", end="")
    print()
