## Edmonds-Karp Algorithm

The provided code implements the Edmonds-Karp algorithm to compute the maximum flow within a flow network. Similar to the Dinic algorithm, this algorithm efficiently finds the maximum flow from a source to a sink within a flow network, making it crucial in solving diverse network flow optimization problems.

* #### Edge Struct
  The Edge structure characterizes an edge, encapsulating attributes such as source, destination, capacity, and current flow through the edge.

* #### Graph Class
  The Graph class is responsible for managing and manipulating the flow network. It features methods for resizing the graph, adding special edges, calculating the maximum flow using the Edmunds-Karp algorithm, and utility functions like BFS for path discovery.

* #### SpecialAdd Function
  The SpecialAdd function augments the graph with edges possessing specific capacities, ensuring the inclusion of both the original edge and a residual edge with zero capacity to support flow management.

* #### BFS Function
  The BFS function executes a breadth-first search to establish the shortest augmenting path within the flow network, considering only available capacity in the edges.

* #### EdmondsKarp Function
  The EdmondsKarp function applies the Edmonds-Karp algorithm to calculate the maximum flow from a source to a sink within the flow network by iteratively identifying and augmenting the shortest augmenting paths through BFS.

* #### Main Function
  The main function serves as the entry point, receiving input for the size of the graph and the capacities of its edges, constructing the graph, computing the maximum flow using the Edmunds-Karp algorithm, and displaying the resulting maximum flow value.

The code efficiently applies the Edmonds-Karp algorithm to compute the maximum flow within a flow network, offering a valuable tool for resolving network flow optimization problems.
