# Get Next Line

Projects goal was to make function which can be used to easily read line from file,
and from perspective of learning, it introduced static variables and little more knowledge of
memory allocation (stack and heap).

The test-gnl that makefile compiles can be used to function like "cat" command, in the sense,
that it reads a file and dumps the contents in to terminal screen.

Main use for the gnl is to send it a file descriptor and an address of char pointer.
Then each call of the gnl will produce one line from a file to that pointer that was sent to gnl.
Example use

<img src="/Images/GNL_usage.png" height=100>
