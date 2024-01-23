# Kth Element

The code provides a generic implementation for finding the k-th (or "kth") element in an array.

* #### Partition Function
The Partition function takes the beginning and ending pointers of an array and partitions the array based on a chosen pivot. It uses the first element as the pivot and rearranges the elements in such a way that all elements less than the pivot appear before it, while all elements greater than the pivot appear after it. It returns a pointer to the pivot element after the partitioning is completed.

* #### KthElement Function
The KthElement function uses the concept of quicksort to find the k-th element in the array. It recursively partitions the array based on a pivot element, and then depending on its position relative to the desired element, it narrows down the search space accordingly. If the pivot is equal to the desired position, the algorithm halts.

This implementation is based on the quickselect algorithm, which is an efficient way to find the k-th smallest or largest element in an unordered list.

In summary, the code offers a convenient and efficient way to find the k-th element within a given array.
