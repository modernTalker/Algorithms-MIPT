# Deque

The provided code introduces Deque as a custom list implementation named List, which consists of a doubly linked list. This implementation allows for operations such as adding and removing elements from the front or back of the list, accessing the front and back elements, checking the size of the list, clearing the list, and gracefully exiting the program.

* #### Node Structure
  The Node structure is a nested private struct within the List class. It represents the individual elements of the doubly linked list and holds a value along with pointers to the previous and next nodes in the list.

* #### List Class
  The List class manages the list structure and includes methods for adding elements to the front or back of the list, removing elements from the front or back, accessing the front and back elements, obtaining the size of the list, clearing the list, and finalizing the program.

* #### Main Function
  The main function forms the interactive user interface of the program. It prompts the user to input the number of subsequent commands and then processes each command accordingly. The program offers a menu-driven interface supporting commands such as "push_front", "push_back", "pop_front", "pop_back", "front", "back", "size", "clear", and "exit".

Upon processing all commands and ensuring the list's cleanliness, the program gracefully terminates its execution.

This custom list implementation, alongside the interactive main function, provides a user-friendly and command-driven environment for showcasing and utilizing the custom list's functionality.
