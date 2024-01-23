# Queue with Minimum Element Support

The provided code introduces a custom queue implementation with additional support for retrieving the minimum element within the queue.

* #### List Class
  The List class acts as a doubly linked list with various functionalities including adding elements to the front or back of the list, removing elements from the front or back, accessing the front and back elements, checking the size of the list, clearing the list, and managing the program's graceful exit.

* #### Stack Class
  The Stack class is built upon the operations of the List class and introduces a stack data structure. It adds functionalities for pushing and popping elements, accessing the top element, checking the size, clearing the stack, and managing the minimum value in the stack.

* #### Queue Class
  The Queue class composes two instances of the Stack class to create a queue. It adds functionalities for queuing and dequeuing items, accessing the top element, checking the queue size, clearing the queue, and managing the minimum value within the queue.

* #### Main Function
  The main function functions as an interactive user interface that reads an integer k from the standard input, representing the number of subsequent commands to be processed. It then processes each command accordingly. The program accepts commands such as "enqueue", "dequeue", "front", "size", "clear", and "min".

Upon processing all commands and ensuring the queues are empty, the program gracefully terminates its execution.

This custom queue implementation showcases a practical example of managing a queue with additional support for retrieving the minimum element within the queue.
