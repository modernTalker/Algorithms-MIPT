# Find Cycle

The provided code is designed to determine whether a graph contains a cycle. It employs a Depth-First Search (DFS) algorithm to traverse the graph and identify cycles within it.

* #### Graph Class
  The Graph class allows for the creation and manipulation of a graph. It includes methods to add edges and determine the presence of a cycle within the graph.

* #### AddEdge Function
  The AddEdge function adds an edge between two vertices in the graph, depicting their connection.

* #### HasCycle Function
  The HasCycle function implements a DFS to identify cycles within the graph. It initializes a color array to track the status of vertices during traversal and utilizes a recursive DFS to detect and return the elements of a cycle if one exists.

* #### HasCycleDFS Function
  The HasCycleDFS function performs the depth-first search to identify whether the graph contains a cycle. It maintains and updates the status of vertices using the color array throughout the DFS traversal.

* #### Main Function
  The main function acts as the entry point, receiving input for the graph's size and connections, constructing the graph, and outputting the presence of a cycle along with its constituent vertices if one exists.

The code effectively applies a DFS-based traversal technique to detect cycles within a graph, providing a valuable tool for analyzing and understanding graph structures in various applications.
