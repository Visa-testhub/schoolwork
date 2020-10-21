# FdF "fils de fer" "wireframe"

This project is introduction to graphical drawing.
<img src="/Images/FdF-objectives.png">

The assignment is in fdf.en.pdf
Main goal is to make program that will be able to display "wireframe" model of file given as parameter
# Example
<img src="/Images/FdF-example.png">

You can use this program by executing the program with the different test maps.
> ./fdf testmaps/z42.fdf

You can also make new maps or modify the old ones.
Maps have couple of rules.
1. Every row must be the same lenght.
2. Some amount of spaces is needed in between the altitules.
#Map example
<img src="/Images/FdF-mapfile.png">

Geometry of the file tells the main foundation of the map and numbers in that file represent
the altitude of each point

You can exit the program by pressing esc or 
Clicking the red cross in the upper left corner.

Requirements for program to work.
- X11 library -lX11 and -lxext and their include files
- Frameworks OpenGL and Appkit

This program is made with mac and thus can offer unstable user experience with linux.
If you have linux system, the program should work,
but I haven't gotten a chance to test it myself.
