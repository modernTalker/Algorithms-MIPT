# Priority Queue

The code contains functions implementing basic heap operations such as pushing elements onto a heap, popping elements from a heap, and the necessary functions for maintaining the heap structure.

* #### Equal Function
This code reuses the Equal function for comparing two elements of type T for equality.

* #### Swap Function
The Swap function is a basic utility function that takes two pointers and swaps the values they point to.

* #### SiftUpHeap Function
The SiftUpHeap function ensures that the element at position i satisfies the heap property with its parent, moving it up the heap as necessary. It compares the element with its parent and swaps them if the heap property is violated. This process continues recursively until the element is in its correct position.

* #### PushHeap Function
The PushHeap function adds a new element at the end of the heap and then uses SiftUpHeap to restore the heap property.

* #### SiftDownHeap Function
The SiftDownHeap function ensures that the element at position i satisfies the heap property with its children, moving it down the heap as necessary. It compares the element with its children and swaps it with the larger child if the heap property is violated. This process continues recursively until the element is in its correct position.

* #### PopHeap Function
The PopHeap function swaps the first element with the last element, effectively removing the largest element from the heap, and then uses SiftDownHeap to restore the heap property.

In summary, this code provides a set of functions for maintaining a heap data structure, enabling efficient addition and removal of elements while preserving the heap invariant.
