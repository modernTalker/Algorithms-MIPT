# Cartesian Tree

The code presents the implementation of a data structure known as a Cartesian Tree, along with the functionality to compute subarray minima. The Cartesian Tree is a binary tree derived from a sequence of distinct elements, possessing the property that it can be generated from the sequence's elements in a specific order.

* #### Node Structure

The Node structure represents a node within the Cartesian Tree. It encapsulates attributes such as the node's value, priority, result, promise, size, and pointers to its parent, left and right sons. The result is a value computed based on the left and right sons of the node, whereas the priority represents the node's priority in the tree construction process.

* #### CartesianTree Class

The CartesianTree class manages the Cartesian Tree structure and supports various operations on the tree, including insertion, deletion, searching for minimum elements in subarrays, and permutation operations.

* #### Insert
  The Insert function adds a new node with a given value and priority at a specified position within the Cartesian Tree.
* #### Erase
  The Erase function removes a node with a specified value from the Cartesian Tree, if it exists.
* #### Exists
  The Exists function checks if a node with a specified value exists within the Cartesian Tree.
* #### Next
  The Next function returns the value of the node next to the node containing a specified value.
* #### Previous
  The Previous function returns the value of the node prior to the node containing a specified value.
* #### Get
  The Get function retrieves the node at a specified position within the Cartesian Tree.
* #### SubarrayMin
  The SubarrayMin function computes the minimum value within a specified subarray of the Cartesian Tree.
* #### Permutation
  The Permutation function performs a permutation operation on the Cartesian Tree, reordering elements based on specified indices.
* #### PrintTree
  The PrintTree function prints the values of the nodes in the Cartesian Tree in ascending order.

* #### Main Function

The main function serves as the entry point, where the user interacts with the Cartesian Tree data structure. It accepts input related to the number of operations to be performed and processes a series of requests, including the addition of new nodes and computation of subarray minima. The Cartesian Tree is dynamically constructed and operated upon based on the user's requests, showcasing the versatility and utility of this data structure in practice.

The code demonstrates the usage of a Cartesian Tree to manage and manipulate a set of distinct elements, showcasing its applicability in solving problems requiring operations such as range queries and dynamic element updates.
