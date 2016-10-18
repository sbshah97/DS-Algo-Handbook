def mergeSort(l):
    if len(l) > 1:
        mid = len(l) // 2
        left = mergeSort(l[:mid])
        right = mergeSort(l[mid:])

        i = j = k = 0;
        while i < len(left) and j < len(right):
            if left[i] > right[j]:
                l[k] = right[j]
                j += 1
            else:
                l[k] = left[i]
                i += 1
            k += 1

        while i < len(left):
            l[k] = left[i]
            k += 1
            i += 1
        while j < len(right):
            l[k] = right[j]
            k += 1
            j += 1

    return l
