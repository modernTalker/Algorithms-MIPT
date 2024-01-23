# Floyd-Warshall Algorithm

The code is centered around finding all-pairs shortest paths in a weighted graph using the Floyd-Warshall algorithm. This algorithm efficiently calculates the shortest paths between all pairs of vertices in a graph, even when the graph contains negative edge weights.

* #### Graph Class
  The Graph class facilitates the handling and manipulation of a weighted graph. It includes methods for resizing the graph, adding weighted edges, and executing the Floyd-Warshall algorithm to determine all-pairs shortest paths.

* #### Resize Function
  The Resize function allows for the resizing of the graph based on the provided size.

* #### SpecialAdd Function
  The SpecialAdd function sets the weight of an edge between two vertices in the graph.

* #### FloydWarshall Function
  The FloydWarshall function implements the Floyd-Warshall algorithm to calculate the shortest paths between all pairs of vertices in the graph. It efficiently iterates through the vertices to update the shortest path distances.

* #### Main Function
  The main function serves as the entry point, receiving input for the size of the graph and its weighted edges, constructing the graph, executing the Floyd-Warshall algorithm, and displaying the resulting shortest path matrix.

The code applies the Floyd-Warshall algorithm to determine all-pairs shortest paths in the weighted graph, providing a valuable tool for analyzing and understanding distance metrics between vertices in various graph structures.
