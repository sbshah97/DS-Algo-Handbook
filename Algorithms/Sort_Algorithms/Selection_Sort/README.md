# SELECTION SORT

It is a comparison-based algorithm in which the list is divided into two parts, the sorted part at the left end and the unsorted part at the right end. Initially, the sorted part is empty and the unsorted part is the entire list.

The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array. This process continues moving unsorted array boundary by one element to the right.

## Example

![Selection Sort](http://www.cs.rmit.edu.au/online/blackboard/chapter/05/documents/contribute/chapter/09/images/selection-sort.gif)

## Algorithm

```
Step 1 − Set MIN to location 0
Step 2 − Search the minimum element in the list
Step 3 − Swap with value at location MIN
Step 4 − Increment MIN to point to next element
Step 5 − Repeat until list is sorted
```

## PSEUDOCODE

Pseudocode of Selection Sort algorithm can be expressed as −

```
procedure selection sort
    list  : array of items
    n     : size of list

    for i = 1 to n - 1
        /* Set current element as minimum */
        min = i

        /* Check the element to be minimum */

        for j = i+1 to n
            if list[j] < list[min] then
                min = j;
            end if
        end for

        /* Swap the minimum element with the current element */
        if indexMin != i  then
            swap list[min] and list[i]
        end if

    end for

end procedure
```

## COMPLEXITY

**Time complexity**  - О(n^2), where n is the number of items being sorted.
**Space complexity** - O(1), due to auxillary space only.

#### Stability

The definition of stable is that the relative order of elements with the same value is maintained even after sorting.

Selection Sort is `Not Stable` 

For eg: when we sort `5 1 2 3 4 5 0` using `selection sort`, After first round 0 will be the minimum value and it will be swapped with the 5 in first position causing change in relative order of the 5's. 
(`0 1 2 3 4 5 5`)

As the relative order of elements having same value(5) is changed, we can clearly state that Selection Sort is not stable.

## Implementation

- [C Code](https://github.com/salman-bhai/DA_A_DS/blob/master/Algorithms/Sort_Algorithms/Selection_Sort/selection-sort.c)
> [Compile Online](https://repl.it/EEPV/3) :rocket:

- [C++ Code](https://github.com/salman-bhai/DA_A_DS/blob/master/Algorithms/Sort_Algorithms/Selection_Sort/selection-sort.cpp)
> [Compile Online](https://repl.it/EEOq/2) :rocket:

- [Java Code](https://github.com/salman-bhai/DA_A_DS/blob/master/Algorithms/Sort_Algorithms/Selection_Sort/selectionsort.java)
> [Compile Online](https://repl.it/EEOv/2) :rocket:

- [Python Code](https://github.com/salman-bhai/DA_A_DS/blob/master/Algorithms/Sort_Algorithms/Selection_Sort/selection-sort.py)
> [Compile Online](https://repl.it/EEPD/1) :rocket:
