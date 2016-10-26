Bucket Sort
--------------

Given a set of n elements, Bucket Sort constructs a set of n buckets into which the elements of the input set are partitioned; Bucket Sort thus reduces its processing costs at the expense of this extra space.

Usage
-------------
You can use Bucket Sort if the following two properties hold:

Uniform distribution
The input data must be uniformly distributed for a given range. Based on this distribution, n buckets are created to evenly partition the input range.

Ordered hash function
The buckets must be ordered. That is, if i<j, then elements inserted into bucket bi are lexicographically smaller than elements in bucket bj.

![Bucket Sort Algorithm](https://www.safaribooksonline.com/library/view/algorithms-in-a/9780596516246/httpatomoreillycomsourceoreillyimages595757.png "Bucket Sort")

Bucket Sort is not appropriate for sorting arbitrary strings, for example; however, it could be used to sort a set of uniformly distributed floating-point numbers in the range [0,1).

Once all elements to be sorted are inserted into the buckets, Bucket Sort extracts the values from left to right using Insertion Sort on the contents of each bucket. This orders the elements in each respective bucket as the values from the buckets are extracted from left to right to repopulate the original array.

Context
---------
Bucket Sort is the fastest sort when the elements to be sorted can be uniformly partitioned using a fast hashing function.

Forces
---------
If storage space is not important and the elements admit to an immediate total ordering, Bucket Sort can take advantage of this extra knowledge for impressive cost savings.

