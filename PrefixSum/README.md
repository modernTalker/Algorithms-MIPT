# Prefix Sum

The code showcases the implementation of a Prefix Table data structure for prefix sum computations and range queries within a given array.

* #### PrefixTable Class

The PrefixTable class is designed to perform prefix sum calculations and efficiently support range queries

* #### Constructor
  The constructor takes in a vector of int64_t values and initializes the Prefix table based on its contents. It computes prefix sums of the input array and uses them to build thePrefix table.
  It sets up the Prefix Table data structure, facilitating effective range queries.

* #### Query Function
  The Query function calculates the prefix sum up to given indices l, r within the underlying array and returns the result.
  It effectively computes the prefix sum, enabling quick access to cumulative sums within the array.
  
* #### Main Function
The main function serves as the entry point for the program, leveraging the PrefixTable class to handle user queries and perform updates on the input array.

It processes user input to create an instance of the FenwickTree class and handles a series of queries and modifications according to user commands.

This implementation utilizes the Prefix table data structure to enable efficient handling of prefix sum calculations and range queries for a given array.
