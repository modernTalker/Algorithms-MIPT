## Disjoint Set Union

The code presents an algorithm to find the minimum number of bridges required to connect different islands. It consists of a DSU (Disjoint Set Union) class and a Graph class along with a main function to interact with the graph and determine the minimum bridges required.

* #### DSU Class
  The DSU class implements the Disjoint Set Union data structure, which provides functionalities to find a set, union two sets, and maintain the count of sets.

* #### Graph Class
  The Graph class is responsible for handling the graph and provides a method to add edges and calculate the minimum number of bridges needed to connect the islands.

* #### SpecialAdd Function
  The SpecialAdd function appends edges to the graph, representing connections between islands.

* #### MinimumBridges Function
  The MinimumBridges function applies the DSU algorithm to determine the minimum number of bridges required to connect all the islands.

* #### Main Function
  The main function acts as the entry point, receiving input for the number of islands and connections, constructing the graph, and outputting the minimum number of bridges required.

The code utilizes the Disjoint Set Union algorithm to determine the minimum number of bridges needed to connect the islands, providing an efficient solution for this connectivity problem.
