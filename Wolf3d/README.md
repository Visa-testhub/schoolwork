# Wolf3d

Projects goal is to make game with dynamic view inside a maze.
I wanted to give the game more retro look with the oldschool looking graphics.

<img src="/Images/Wolf3d-view.png" height=200>

Objectives for this project is to get more comfortable with  windows(as in windnow in screen),
colors, events, raycasting, basic alorithms and textures.
From graphical libraries only window management functions , envent management and functions to light up individual
pixels in screen are used

<img src="/Images/Wolf3d-diffwall.png" height=200>

# to use:
>make

>./wolf3d maps/level_1

Requirements are
· X11 header file in /usr/local/include/X11
· -lX11 and -lXext in /usr/X11/lib
· Frameworks OpenGL and Appkit
If you have the header files or libraries in different place, you can change the path in the makefile.

Readme in wolf3d/maps will help you to make your own maps. 
