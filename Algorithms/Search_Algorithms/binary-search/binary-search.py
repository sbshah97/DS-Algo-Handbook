
def binarySearch(arr, l, r, x):

    if r >= l:

        mid = l + (r - l)//2

        if arr[mid] == x:
            return mid

        elif arr[mid] > x:
            return binarySearch(arr, l, mid-1, x)

        else:
            return binarySearch(arr, mid+1, r, x)

    else:
        return -1


seq= list()
n = int(input())

for i in range(n):
    seq.append(int(input()))

value = int(input())

# tempseq = sorted(seq)

result = binarySearch(seq, 0, len(seq)-1, value)

print(result+1)   # index of the element in the array and if not exists return -1