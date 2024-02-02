# Segment Tree

The supplied code demonstrates the implementation of a Segment Tree equipped with lazy propagation for efficiently handling range maximum queries and range updates within a given array.

* #### SegmentTree Class

  The SegmentTree class has been designed to facilitate efficient range maximum queries and range updates, leveraging the concept of lazy propagation to optimize updates across a given range.

  * #### Constructor
    - The constructor initializes the Segment Tree along with its associated data structures based on the input array. It also computes the segment tree nodes and prepares them for performing range maximum queries and updates.
    - It employs lazy propagation to defer updates until necessary, enhancing efficiency.

  * #### Update Function (U)
    - The U (short for Update) function enables the modification of elements within a given range by applying a delta value to the specified range. It utilizes the concept of lazy propagation to defer updates and efficiently perform modifications.

  * #### Query Function (Q)
    - The Q function handles range maximum queries, computing the maximum value within a given range of the original array using the prepared segment tree nodes and lazy propagation techniques.

* #### Main Function
  The program's main function serves as the entry point, managing user queries and updates to the segment tree.

  - It processes user input to create an instance of the SegmentTree class and handles a series of queries and modifications as directed by user commands.

This implementation demonstrates the utilization of a Segment Tree with lazy propagation to enable handling of range maximum queries and updates within a given array.
