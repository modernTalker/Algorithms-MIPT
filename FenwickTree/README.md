# Fenwick Tree

The code showcases the implementation of a Fenwick tree (also known as a Binary Indexed Tree) for efficient prefix sum computations and range queries within a given array.

* #### FenwickTree Class

The FenwickTree class is designed to perform prefix sum calculations and efficiently support range queries and updates within a given array.

* #### Constructor
  The constructor takes in a vector of int64_t values and initializes the Fenwick tree based on its contents. It computes prefix sums of the input array and uses them to build the Fenwick tree.
  It sets up the Fenwick tree data structure, facilitating effective range queries and updates.

* #### Update Function
  The Update function modifies the Fenwick tree by updating the value of an element at a specific index and adjusting the tree structure accordingly.
  This method allows for efficient modifications to the underlying array and updates the Fenwick tree to reflect these changes.

* #### Query Function
  The Query function calculates the prefix sum up to a given index r within the underlying array and returns the result.
  It effectively computes the prefix sum, enabling quick access to cumulative sums within the array.

* #### Q Function
  The Q function handles range queries, computing the sum of values within a given range [l, r] of the original array through clever usage of the prefix sums stored in the Fenwick tree.

* #### Main Function
The main function serves as the entry point for the program, leveraging the FenwickTree class to handle user queries and perform updates on the input array.

It processes user input to create an instance of the FenwickTree class and handles a series of queries and modifications according to user commands.

This implementation utilizes the Fenwick tree data structure to enable efficient handling of prefix sum calculations and range queries for a given array.
