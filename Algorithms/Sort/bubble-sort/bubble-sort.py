#!/usr/bin/env python3
# Written by @daydreamer at Oct 12, 2016. Trying to do same behaviour as the C code
# Except for the input part
sz = int(input('enter the number of elements to input:\n'))
ar = list(map(int, input('enter the elements:\n').split(' ')))

print("array before sorting:")
for item in ar:
    print(item)

for i in range(sz-1):
    for j in range(sz-1-i):
        if ar[j] > ar[j+1]:
            ar[j], ar[j+1] = ar[j+1], ar[j]

print("array after sorting:")
for item in ar:
    print(item)
