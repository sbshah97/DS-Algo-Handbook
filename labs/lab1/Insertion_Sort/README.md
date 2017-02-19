# Insertion Sort

## Algorithm
1. for i = 0 .. n-1
2. 		x = arr[i]
3. 		j = i - 1
4. 		while (arr[j] > x && j >= 0)
5.			count = count + 1
6. 			arr[j+1] = arr[j]
7. 			j = j - 1
8. 		arr[j+1] = x

## Logic

* 