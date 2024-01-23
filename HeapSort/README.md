# Heap Sort

The code offers additional functions related to heap operations, including building a heap, sifting down, and sorting a heap.

* #### Swap Function
The Swap function is a basic utility function that takes two pointers and swaps the values they point to.

* #### LeftChild and RightChild Functions
These functions compute the indices of the left and right child of a node in a binary heap, based on the index of the node.

* #### SiftDown Function
The SiftDown function maintains the heap property from a given node down through its children. It finds the largest element among the node and its children, swaps the node with the largest of the three if necessary, and continues this process recursively until the element is in its correct position.

* #### MakeHeap Function
The MakeHeap function turns the provided range into a heap, assuming that the elements are initially in arbitrary order. It uses SiftDown on each non-leaf node to build the heap.

* #### SortHeap Function
The SortHeap function sorts the heap represented by the given range into ascending order. It repeatedly extracts the maximum element from the heap and restores the heap property.

These functions provide a complete set of operations for managing a heap data structure, including building a heap from an unsorted array and sorting a heap efficiently.
