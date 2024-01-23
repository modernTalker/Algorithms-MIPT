# Bridge Detection in a Graph

The code demonstrates bridge detection in a graph using depth-first search (DFS). It outlines the graph structure and functionalities for adding edges, exploring the graph, and identifying bridge edges.

* #### Graph Class
  The Graph class defines an undirected graph and provides operations to add edges, retrieve neighbors, and perform depth-first search (DFS) to identify bridge edges.

* #### AddEdge Function
  The AddEdge function efficiently adds an edge between two vertices in the graph, capturing the edge index as well.

* #### DFS and DFSvisit Functions
  - The DFS function initiates the depth-first search algorithm to find bridges within the graph.
  - The DFSvisit function explores each vertex, identifying bridge edges based on the discovery and finishing times during the DFS traversal.

* #### Main Function
  The main function acts as a user interface, receiving input for the number of vertices and edges in the graph and specifying the edges. It then computes and displays the number of bridge edges and their respective indices within the graph.

This program provides an effective solution for identifying bridge edges in a graph, offering valuable insights into the connectivity and critical edges within the graph structure.
