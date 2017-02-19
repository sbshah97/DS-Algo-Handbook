# Selection Sort

## Algorithm
1. for i = 0 .. n-1
2. 		small = i
3. 		for j = i+1 .. n
4.			count += 1
5.			if arr[j] < arr[small]
6.				small = j
7.			temp = arr[i]
8.			arr[i] = arr[small]
9.			arr[small] = temp
