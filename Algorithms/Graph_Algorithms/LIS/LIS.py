# This Program gives you Longest increasing subsequence using DP.  

# Time complexity: O(n * n)

# Input Format:
# First line has integer n where n=number of elements in array.
# The next  line n integer elements of array.

# Output Format:
# Print LIS and its length

def find_longest_increasing_subsequence(ar):
    dp=[]

    # Initialising the value for first array element
    dp.append(1)

    for i in range(1,len(ar)):

        if ar[i]>ar[i-1]:
            # As for any indivisual element minimum length can be 1  for itself
            dp.append(1)
            # After checking the previous element increementing the count from the counter variable of the previous value itself(DP)
            dp[i]=dp[i-1]+1


        else:
            dp.append(1)

    pos=dp.index(max(dp))
    print("Longest subsequence array is ")
    #pos+1 because slicing needs +1 for going to the exact position we want to
    print(ar[pos+1-max(dp):pos+1])
    return max(dp)

n=raw_input()
array = [int(x) for x in raw_input().split()]

print("Longest Length of increasing subsequence is "+str(find_longest_increasing_subsequence(array)))
