# Boruvka's Algorithm

The code implements Boruvka's algorithm to find the Minimum Spanning Tree (MST) in a graph. A Minimum Spanning Tree spans all the vertices of the graph with the minimum total edge weight.

* #### DSU Class
The DSU class represents the Disjoint Set Union data structure, providing functionalities for finding sets, union operations, and maintaining the count of sets.

* #### Edge Struct
The Edge structure signifies an edge within the graph, containing attributes for weight, source vertex, target vertex, and a flag to indicate if the edge has been visited.

* #### Graph Class
The Graph class manages the graph and provides methods for adding edges and computing the Minimum Spanning Tree weight using Boruvka's algorithm.

* #### SpecialAdd Function
The SpecialAdd function adds an edge to the graph, specifying the weight and the vertices it connects.

* #### Boruvka Function
The Boruvka function applies Boruvka's algorithm to find the Minimum Spanning Tree weight, utilizing the Disjoint Set Union (DSU) data structure to iteratively select edges with the minimum weight and merge the corresponding components.

* #### Main Function
The main function serves as the entry point, receiving input for the graph's size and the edges' weights, constructing the graph, executing Boruvka's algorithm to compute the Minimum Spanning Tree weight, and displaying the resulting weight.

The code efficiently applies Boruvka's algorithm to compute the Minimum Spanning Tree weight, providing an essential tool for analyzing graph structures and identifying the minimum total weight to connect all vertices.
