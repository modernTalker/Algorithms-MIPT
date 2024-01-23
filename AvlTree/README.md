# AVL Tree

The provided code introduces an AVL (Adelson-Velsky and Landis) tree, an efficient self-balancing binary search tree, with functionalities for inserting nodes, balancing the tree, obtaining the tree height, and efficiently finding the successor for a given value.

* #### Node Structure
  The Node struct within the Avl class represents elements within the AVL tree. It includes a value, node height, and pointers to the left child, right child, and parent nodes.

* #### Bfactor Function and Height Functions
  The Bfactor and Height functions help determine the balancing factor and height of a given node within the AVL tree.

* #### RightRotate and LeftRotate Functions
  The RightRotate and LeftRotate functions are used to perform right and left rotations, respectively, when balancing the AVL tree.

* #### Balance Function
  The Balance function evaluates the balance factor of a node and performs rotations as necessary to maintain the balance of the AVL tree.

* #### Insert and InsertNode Functions
  The Insert and InsertNode functions enable the insertion of a new node into the AVL tree while ensuring the tree remains balanced after the insertion.

* #### ClearNode and Clear Functions
  The ClearNode and Clear functions facilitate the clearing of the entire AVL tree by deleting each node from memory, ensuring proper memory management.

* #### InorderWalk, Maximum, and Search Functions
  - The InorderWalk function performs an in-order tree traversal and finds the immediate successor in the sorted sequence.
  - The Maximum function returns the node with the maximum value in the AVL tree.
  - The Search function traverses the tree to find a specific node based on its value.

* #### Next Function
  The Next function efficiently computes the successor value of a given input within the AVL tree.

* #### Main Function
  The main function acts as a user interface, allowing the user to insert values into the AVL tree, find the immediate successor, and efficiently maintain the tree as values are inserted.

This program effectively demonstrates the functionality of an AVL tree, enabling the insertion of nodes, maintenance of balance, finding successors, and height management.
