# fract'ol
<img src="/Images/Fractol-julia-example.png">

Fractol focuses on honing skills on schools own graphical library, Minilibx,
discovering some uses for complex numbers and consept of optimization on computer graphics.

To learn about fractals check out wikipedia page 
https://en.wikipedia.org/wiki/Fractal

I tought this was great opportunity to learn simple use of multithreading as a way of
making the program faster, and it worked like a charm, as this program is noticeably
faster.

To use
1. > make
2. > ./fractol Julia
<img src="/Images/Fractol-usage.png">

Minilibx requires following to work.
- X11 and xextension library -lXext -lX11 in /usr/X11/lib
- X11 librarys includes in /usr/local/include/X11
- Frameworks OpenGL and Appkit

This project is made with macOS Catalina and is not tested in any other device,
but if all the requiremets are fulfilled it should work.
