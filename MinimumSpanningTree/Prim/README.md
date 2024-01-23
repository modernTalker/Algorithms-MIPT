# Prim's Algorithm
The code implements Boruvka's algorithm to find the Minimum Spanning Tree (MST) in a graph. A Minimum Spanning Tree spans all the vertices of the graph with the minimum total edge weight.
* #### Comparator Struct
The Comparator struct acts as a custom comparator for the priority queue in the Prim function within the Graph class.

* #### Graph Class
The Graph class handles the graph, offering methods for resizing, adding special edges, and computing the Minimum Spanning Tree weight using Prim's algorithm.

* #### SpecialAdd Function
The SpecialAdd function is used to add an edge to the graph, recording the weight and the vertices connected.

* #### Prim Function
The Prim function applies Prim's algorithm to compute the Minimum Spanning Tree weight. It utilizes a priority queue to select vertices with the minimum weight, effectively constructing the Minimum Spanning Tree and calculating the total weight.

* #### Main Function
The main function serves as the entry point, taking input for the graph's size and the weights of its edges, constructing the graph, executing Prim's algorithm to compute the Minimum Spanning Tree weight, and displaying the resulting weight.

The code efficiently utilizes Prim's algorithm to compute the Minimum Spanning Tree weight, providing a fundamental tool for analyzing graph structures and finding the minimum total weight to connect all vertices.
