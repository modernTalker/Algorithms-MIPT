# Suffix Tree
The code demonstrates the construction of a suffix tree using an underlying suffix automaton, enabling substring matching and facilitating advanced operations on a given string.

* #### SuffixAutomaton Class

  The SuffixAutomaton class creates a suffix automaton and manages the addition of symbols to construct the required underlying structure for the suffix tree.

  - #### Constructors and Functions
    The class effectively constructs the suffix automaton and provides functionalities to add symbols and traverse the built automaton, preparing the foundation for the subsequent suffix tree construction.

* #### SuffixTree Class

  The SuffixTree class leverages the constructed suffix automaton to build the corresponding suffix tree, emphasizing the extraction of transitions and the subsequent construction of the tree.

  - #### Constructor and Functions
     The class constructs the suffix tree by deriving transitions and node characteristics using the pre-built suffix automaton, allowing for appropriate traversal and outputting the constructed tree.

This implementation creates a suffix tree based on the underlying suffix automaton, outlining the hierarchical structural relationships and transitions within the given string.
