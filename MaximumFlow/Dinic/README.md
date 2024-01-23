# Dinic Algorithm

The presented code outlines the application of the Dinic algorithm to compute the maximum flow in a flow network. The Dinic algorithm efficiently finds the maximum flow between a source and a sink within a flow network, offering a crucial tool in network flow optimization problems, such as in transportation and communication networks.

* #### Edge Struct
  The Edge structure defines properties for an edge, including the source, destination, capacity, and current flow through the edge.

* #### Graph Class
  The Graph class facilitates the management and manipulation of a flow network. It incorporates methods for resizing the graph, adding special edges, computing the maximum flow using the Dinic algorithm, and auxiliary functions like BFS and DFS for flow calculation.

* #### SpecialAdd Function
  The SpecialAdd function adds edges to the graph with specified capacities, maintaining both the original edge and a residual edge with zero capacity to assist in flow management.

* #### BFS Function
  The BFS function performs a breadth-first search to establish the level graph for potential path discovery within the flow network, considering only edges with available capacity.

* #### DFS Function
  The DFS function executes a depth-first search to determine the flow through individual edges in the flow network, utilizing the level graph obtained from the BFS operation.

* #### Dinic Function
  The Dinic function implements the Dinic algorithm to compute the maximum flow between a source and a sink within the flow network, efficiently utilizing BFS and DFS to determine the flow paths and compute the maximum flow.

* #### Main Function
  The main function serves as the entry point, receiving input for the size of the graph and its edges' capacities, constructing the graph, computing the maximum flow using the Dinic algorithm, and outputting the resulting maximum flow value.

The code effectively applies the Dinic algorithm to determine the maximum flow within a flow network, presenting a valuable tool for network flow optimization problems.
