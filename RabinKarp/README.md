# Rabin-Karp Algorithm
The code showcases the Rabin-Karp algorithm enhanced to count the number of cyclic shifts of a pattern within a longer text.

* #### RabinKarp Class

  The RabinKarp class is designed to facilitate efficient hashing operations and substring comparisons using the Rabin-Karp algorithm.

* #### Constructor
  The constructor initializes the Rabin-Karp hashing mechanism for the provided string and prepares it for substring hash computations.
  
* #### SubstringHash Function
  The SubstringHash function computes the hash values for a given substring, providing a pair of integers as the resulting hash values.

* #### CycleShiftsCount Function

  The CycleShiftsCount function employs Rabin-Karp hashing to count the occurrences of cyclic shifts of a given pattern within a longer text.

  It utilizes Rabin-Karp hashing to compute the hash values for cyclic shifts of the pattern and checks for their occurrence within the text, incrementing a counter for each match.

* #### Main Function

  The main function acts as the entry point for user interaction. It accepts user input for the pattern and the text, calls the CycleShiftsCount function to determine the number of cyclic shifts of the pattern in the text, and subsequently outputs the result.

This implementation leverages Rabin-Karp hashing to compute and count the cyclic occurrences of a pattern within a larger text, providing a tool for substring matching and cyclic shift assessment.
