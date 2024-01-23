# Kruskal's Algorithm
The code implements Boruvka's algorithm to find the Minimum Spanning Tree (MST) in a graph. A Minimum Spanning Tree spans all the vertices of the graph with the minimum total edge weight.

* #### DSU Class
The DSU (Disjoint Set Union) class serves for managing disjoint sets, allowing for union and find operations to merge sets and locate the representative element of the set to which an element belongs.

* #### Comparator Struct
The Comparator struct is defined to act as a custom comparator, particularly for the priority queue in the Graph class.

* #### Graph Class
The Graph class manages the graph, providing functionalities for resizing, adding special edges, and computing the Minimum Spanning Tree weight using Kruskal's algorithm.

* #### SpecialAdd Function
The SpecialAdd function adds an edge to the graph, with the weight and the vertices it connects.

* #### Kruskal Function
The Kruskal function applies Kruskal's algorithm to find the Minimum Spanning Tree weight, utilizing a priority queue to efficiently select edges with the minimum weight, while employing the disjoint set union data structure to merge sets and identify the Minimum Spanning Tree.

* #### Main Function
The main function serves as the entry point, receiving input for the graph's size and the weights of its edges, constructing the graph, executing Kruskal's algorithm to compute the Minimum Spanning Tree weight, and displaying the resulting weight.

The code utilizes Kruskal's algorithm to compute the Minimum Spanning Tree weight, offering an essential tool for analyzing graph structures and identifying the minimum total weight to connect all vertices.
