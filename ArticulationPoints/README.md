# Articulation Points

The code exemplifies the identification of articulation points in a graph using depth-first search (DFS). It represents a graph and offers functionalities to add edges, explore the graph, and identify articulation points.

* #### Graph Class
  The Graph class represents an undirected graph. It provides operations to add edges, retrieve neighbors, and perform depth-first search (DFS) to identify articulation points.

* #### AddEdge Function
  The AddEdge function effectively adds an edge between two vertices in the graph.

* #### DFS and DFSvisit Functions
  - The DFS function initiates the depth-first search algorithm to find articulation points within the graph.
  - The DFSvisit function explores each vertex, updating the state of the vertices and identifying articulation points.

* #### Main Function
  The main function serves as the user interface, receiving input for the number of vertices and edges in the graph and specifying the edges. It then computes and displays the number of articulation points and their respective indices in the graph.

This program demonstrates the use of depth-first search to identify articulation points in a graph, providing a practical method to analyze the structure of the graph and locate critical points.
