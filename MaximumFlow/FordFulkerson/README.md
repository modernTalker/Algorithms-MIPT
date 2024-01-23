# Ford-Fulkerson Algorithm

The code illustrates the implementation of the Ford-Fulkerson algorithm to calculate the maximum flow within a flow network. Similar to the previous flow algorithms, this algorithm is paramount in solving network flow optimization problems.

* #### Edge Struct
  The Edge structure characterizes an edge, encapsulating attributes such as source, destination, capacity, and current flow through the edge.

* #### Graph Class
  The Graph class manages and manipulates the flow network. It comprises methods for resizing the graph, adding special edges, computing the maximum flow using the Ford-Fulkerson algorithm, and auxiliary functions like DFS for flow calculation.

* #### SpecialAdd Function
  The SpecialAdd function augments the graph with edges having specific capacities, ensuring the incorporation of both the original edge and a residual edge with zero capacity to aid in flow management.

* #### DFS Function
  The DFS function executes a depth-first search to identify the flow paths within the flow network, considering a specific minimum capacity for the edges.

* #### DFSVisit Function
  The DFSVisit function is invoked within the DFS function to conduct the depth-first search while keeping track of visited nodes and achieving the required flow augmentation.

* #### FordFulkerson Function
  The FordFulkerson function applies the Ford-Fulkerson algorithm to determine the maximum flow within the flow network, iteratively adjusting the flow and revisiting paths as per the algorithm's specifications.

* #### Main Function
  The main function serves as the entry point, receiving input for the graph's size and the capacities of its edges, constructing the graph, computing the maximum flow using the Ford-Fulkerson algorithm, and displaying the resulting maximum flow value.

The code effectively applies the Ford-Fulkerson algorithm to compute the maximum flow within a flow network, presenting a fundamental tool for addressing network flow optimization problems.
