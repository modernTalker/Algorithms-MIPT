# Strongly Connected Components

The code includes functionalities for finding the Strongly Connected Components (SCC) in a directed graph using Topological Sort and Depth-First Search (DFS).

* #### Contain Function
The Contain function checks the existence of a specific character within a given string.

* #### Reversed Function
The Reversed function reverses an array of integers.

* #### Graph Class
The Graph class manages the directed graph and performs crucial operations for SCC computation, such as adding edges, determining various graph properties, conducting Topological Sort, and implementing DFS for both the original and transposed graphs.

* #### AddEdge Function
The AddEdge function facilitates the addition of an edge between two vertices within the graph.

* #### Size Function
The Size function returns the number of vertices in the graph.

* #### Neighbours Function
The Neighbours function retrieves the neighboring vertices of a specified vertex in the graph.

* #### TransposedNeighbours Function
The TransposedNeighbours function retrieves the transposed neighbors of a specified vertex.

* #### TopSort Function
The TopSort function executes a Topological Sort on the graph, providing an ordering of the vertices based on directed dependencies.

* #### DFS, DFSvisit Functions
The DFS and DFSvisit functions perform Depth-First Search to identify Strongly Connected Components within the graph.

* #### TransposedDFS, TransposedDFSvisit Functions
The TransposedDFS and TransposedDFSvisit functions conduct Depth-First Search on the transposed graph to identify Strongly Connected Components.

* #### Main Function
The main function serves as the entry point, processing input for the graph's size and edges, constructing the graph, calculating the Strongly Connected Components using Depth-First Search and Topological Sorting, and displaying the resulting components alongside distribution information.

The code leverages Topological Sort and Depth-First Search to compute the Strongly Connected Components within a directed graph, providing insights into the relational structures within the graph.
