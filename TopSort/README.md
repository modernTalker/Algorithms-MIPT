# Topological Sorting

The code offers a solution for implementing Topological Sorting in a directed graph. It leverages Depth-First Search (DFS) to create a topologically sorted order of the vertices within the graph.

* #### Contain Function
The Contain function searches for a specific character within a given string, returning a boolean based on the character's presence.

* #### Reversed Function
The Reversed function produces a reversed variant of a given array of integers, creating a reversed order of the elements.

* #### Graph Class
The Graph class manages the directed graph and conducts operations pertinent to the Topological Sort algorithm, involving the addition of edges, determination of graph properties, and the application of the Topological Sort algorithm.

* #### AddEdge Function
The AddEdge function adds a directed edge between two vertices within the graph.

* #### Size Function
The Size function returns the number of vertices within the graph.

* #### Neighbours Function
The Neighbours function retrieves the neighboring vertices of a specified vertex within the graph.

* #### TopSort Function
The TopSort function initiates the topological sorting process by utilizing Depth-First Search (DFS) to create a topologically sorted order of the vertices.

* #### TopSortDFS Function
The TopSortDFS function conducts the Depth-First Search to establish the topologically sorted order of the graph's vertices, ensuring that there are no cycles in the graph.

* #### Main Function
The main function serves as the entry point, acquiring input for the graph's size and the edges, constructing the graph, executing the Topological Sort algorithm, and exhibiting the resulting topologically sorted order of the vertices, or indicating if a topological sort is not possible in the presence of a cyclic dependency.

The code utilizes Depth-First Search (DFS) to conduct Topological Sorting, enabling an organized order of the graph's vertices, or detecting the absence of a valid topological sort in the presence of cyclic dependencies.
