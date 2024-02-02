# Knuth-Morris-Pratt Algorithm

The provided code exhibits the implementation of the Knuth-Morris-Pratt (KMP) algorithm, which efficiently searches for occurrences of a given pattern within a larger string.

* #### PiFunction Class

  The PiFunction class encapsulates the prefix function, responsible for generating the prefix values crucial for the KMP algorithm. It efficiently computes the prefix function values for a given string, which are used to determine the shifting of the pattern during search operations.

* #### Constructor
- The constructor initializes the prefix function based on the provided string, applying the KMP algorithm to efficiently compute and store the necessary prefix function values.

* #### Operator Overload
- The operator[] overload facilitates direct access to the computed prefix function values.

* #### KMP Function

  The KMP function, utilizing the prefix function, conducts the actual pattern search within the string. It constructs an augmented string containing the pattern and the search string, computes the prefix function for this augmented string, and efficiently identifies the positions of the occurring pattern within the search string.

* #### Main Function

  The main function serves as the entry point for user interaction. It accepts user input for the search string and the pattern to be found, runs the KMP algorithm to find occurrences of the pattern within the string, and outputs the positions where the pattern appears.

This implementation proficiently leverages the Knuth-Morris-Pratt algorithm for efficient pattern searching within a given string, thus providing an effective tool for pattern matching and substring detection.
