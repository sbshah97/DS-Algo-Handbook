#!/usr/bin/env python3
n = int(input('Please input list length n: '))
a = list(map(int, input('Please input the list, seperated by space: ').split()))

for i in range(n):
    for j in range(i+1, n):
        if a[i] > a[j]:
            a[i], a[j] = a[j], a[i]

print('\n'.join(list(map(str, a))))

