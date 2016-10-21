#Program to find Longest common subsequence

# Input format
# first line of input contains 2 integer length of 2 sequences
# next 2 line each contain n and m integer

# Output format
# output prints the longest common subsequence



def LCS(X, n, Y, m):
    list1 = [[0 for i in xrange(m + 1)] for j in xrange(n + 1)]
    for i in xrange(n + 1):
        list1[i][m] = 0
    for j in xrange(m + 1):
        list1[n][j] = 0

    for i in xrange(n - 1, -1, -1):
        for j in xrange(m - 1, -1, -1):
            list1[i][j] = list1[i + 1][j + 1]
            if (X[i] == Y[j]):
                list1[i][j] += 1
            if (list1[i][j + 1] > list1[i + 1][j + 1]):
                list1[i][j] = list1[i][j + 1]
            if (list1[i + 1][j] > list1[i][j]):
                list1[i][j] = list1[i + 1][j]

    return list1


def main():
    N, M = raw_input().split()
    n = int(N)
    m = int(M)
    string1 = raw_input().split()
    string2 = raw_input().split()
    list1 = LCS(string1, n, string2, m)

    solution = []
    i = 0
    j = 0
    while i < n and j < m:
    	a, b, c = list1[i+1][j], list1[i+1][j+1], list1[i][j+1]
    	max_val = max(a, b, c)

    	if b == max_val:
    	    i += 1
    	    j += 1

    	elif a == max_val:
    	    i += 1

    	elif c == max_val:
	    j += 1

	if string1[i-1] == string2[j-1]:
	    solution.append(string1[i-1])

    string = ""
    for i in xrange(len(solution)):
    	string += (str(solution[i]) + " ")
    print string
    return 0

if __name__ == "__main__":
    main()
