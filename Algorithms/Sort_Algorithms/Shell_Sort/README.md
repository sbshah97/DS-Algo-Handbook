#Shell Sort

The shell sort, sometimes called the “diminishing increment sort,” improves on the insertion sort by breaking the original list into a 
number of smaller sublists, each of which is sorted using an insertion sort. 

The unique way that these sublists are chosen is the key to the shell sort.

Instead of breaking the list into sublists of contiguous items, the shell sort uses an increment i, sometimes called the gap, to create 
a sublist by choosing all items that are i items apart.

##Pseudo-Code
Shell.Sort(num,n,key)
* 1. Assign span=n/2
* 2. while span>0 do:
+      a) for i from span to n-1, repeat steps b,c,e
+      b) key=num[i], j=i
+      c)while j=span and num[j-span]>key, repeat step d
+      d) swap num[j] and num[j-span]
+      e) span = span/2

Use Insertion Sort to sort remaining array of data 

##Complexity
Time complexity of shellsort is O(N*N).
