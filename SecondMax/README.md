# Second Maximum

The provided code introduces a binary tree, along with functionalities for insertion, clearing, and obtaining particular values within the tree.

* #### Node Structure
  The Node struct within the BinaryTree class represents elements within the binary tree. It includes a value along with pointers to the left child, right child, and parent nodes.

* #### Insert Function
  The Insert function adds a new node to the binary tree. It efficiently traverses the tree to find the correct position for the new node based on its value and updates the tree's height if necessary.

* #### Clear Function
  The Clear function clears the entire binary tree by deleting each node from memory, ensuring proper memory management.

* #### Height Function
   The Height function returns the height of the binary tree, providing the maximum level of the tree.

* #### Maximum and ParentMax Functions
  - The Maximum function returns a pointer to the node with the maximum value in the tree.
  - The ParentMax function finds the parent of the node with the maximum value.

* #### SecondMax Function
  The SecondMax function retrieves the second maximum value from the binary tree. It traverses the tree's nodes to find the second maximum based on the relationships between nodes.

* #### Main Function
  The main function acts as a user interface, allowing the user to input values to be inserted into the binary tree. Once all values are inserted, it outputs the second maximum value in the binary tree and clears the tree.

This program demonstrates the functionality of a binary tree, enabling the insertion of values and the retrieval of specific node values such as the maximum, second maximum, and overall tree height.
