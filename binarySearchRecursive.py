"""
    Pre: List ordered asc, variable to find
    Post: Returns the position of the variable (x). If the variable is not in the list => return -1
"""
def binarySearchRecursive(l, x):
    return r_binarySearchRecursive(l, x, 0, len(l) - 1)

def r_binarySearchRecursive(l, x, left, right):
    if left > right:
        return -1
    mid = (left + right) // 2
    if x < l[mid]:
        return r_binarySearchRecursive(l, x, left, mid-1)
    elif x > l[mid]:
        return r_binarySearchRecursive(l, x, mid+1, right)
    else:
        return mid


""" For example, I try the algorithm in this basic list """
l = [1, 2, 3, 4, 5, 6, 7, 8, 9]

""" The list contains the number 4 => binarySearchRecursive() will retrun the position of 4 in the list """
print binarySearchRecursive(l, 4)
""" The list not contains the number 10 => binarySearchRecursive() will retrun -1"""
print binarySearchRecursive(l, 10)
