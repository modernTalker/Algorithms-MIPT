# Merge Sort
The code implements a generic Merge Sort and related auxiliary functions for sorting an array of elements.

* #### Equal Function
This code reuses the Equal function for comparing two elements of type T for equality.

* #### Merge Function
The Merge function merges two sorted subarrays into a single sorted array. It takes two pairs of pointers, each representing the beginning and end of a sorted subarray, and merges them into a single output array in sorted order.

* #### MergeSort Function
The MergeSort function is a recursive implementation of the merge sort algorithm. It sorts the subarray defined by the given left and right pointers in ascending order using the merge function. It splits the array into two subarrays and sorts each of them recursively. Then it merges the two sorted subarrays into a single sorted array.

* #### Sort Function
The Sort function is the entry point for the merge sort algorithm. It takes the beginning and end pointers of the array to be sorted, initializes a temporary array for storing the sorted result, applies the MergeSort algorithm, and then copies the sorted elements back into the original array.

In summary, this code implements of the well-known merge sort algorithm, which is known for its stable, efficient, and consistently fast performance on a wide range of input data types.
