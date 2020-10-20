# Fillit

This projects target is to familiarize one with recursion and optimization.
Assignment tells student to find a way to assemble given Tetriminos set in the smallest possible square

 <img src="/Images/Tetriminos.png" widht=200 height=100 >< Tetriminos
 
 The assignement can be read from fillit.en.pdf
 
 As one of the goals of this project is optimization, I chose to approach this problem solving with bitwise operations,
 which I had heard at the time were lots of faster but didn't know a thing about.
 
 During this project I learned a lot about recursion, enumerations, bitsifting and different thinking style about numbers.
 One thing that I think was important was to think differently about numbers and their bits.
 As the program has to take in file which has 4 rows, each having four dots in then or in place of the dots, a hash symbol #,
 
 <img src="/Images/Tetrimino-piece.png" widht=40 height=60>
 Easier way may have been to transfer those rows to character strings and modify them, but as I wanted to do the project with
 bits I took them in and transferred them to unsigned long:s.
 Because of that, the numbers had to be thinked as a four 16 bit long rows, and all the tetriminos as numbers that represented
 rows which had bits on or off.
   <img src="/Images/Bit-rows.png" widht=120 height=60>
 
# How to use:
make && ./fillit example_tetriminos

<img src="/Images/Usage_example.png" widht=50>.
