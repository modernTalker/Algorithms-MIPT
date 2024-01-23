# Binary Search

The provided code presents a set of functions for performing binary search and obtaining the lower and upper bounds within a given array.

* #### Equal Function
  The Equal function compares two elements of type T for equality. It returns true if the two elements are equal, and false otherwise. The comparison is done by inverting the outcome of the less-than and greater-than comparisons.

* #### BinarySearch Function
  The BinarySearch function performs a binary search within the sorted array to find a given value. It efficiently narrows down the range of possible indices containing the value until it is either found or determined not to be present.

* #### LowerBound and UpperBound Functions
  - The LowerBound function returns an iterator pointing to the first element in the array that is not less than the given value. It identifies the first occurrence (if any) of an element greater than or equal to the given value.
  - The UpperBound function returns an iterator pointing to the first element in the array that is greater than the given value. It identifies the first occurrence (if any) of an element strictly greater than the given value.

These functions, collectively, provide efficient tools for analyzing and locating elements within a sorted array, along with support for performing binary search and obtaining boundaries for a given value.
