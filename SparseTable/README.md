# Sparse Table

The code provides an implementation of a Sparse Table data structure tailored to handle range minimum queries within a given 2D array.

* #### SparseTable Class

  The SparseTable class is engineered to maintain a sparse table suitable for conducting range minimum queries (RMQ) on a 2D array.

  * #### Constructor
    - The constructor initializes the Sparse Table with the provided 2D array by computing and populating the necessary table entries, considering both rows and columns.
    - It leverages the concept of a sparse table to store precomputed minimum values for various range sizes, supporting efficient RMQ operations.

  * #### Query Function
    - The Query function facilitates range minimum queries within the 2D array. Utilizing the precomputed table, it efficiently retrieves the minimum value within the specified range using the calculated minimum values stored in the table.

The program's main function serves as the entry point, accepting user input to initialize the 2D array and conduct a series of range minimum queries using the SparseTable class.

The implementation employs a Sparse Table data structure for handling of range minimum queries within the provided 2D array.
