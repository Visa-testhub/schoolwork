all:
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	/bin/rm -rf main.o get_next_line.o

fclean:	clean
	/bin/rm -rf test_gnl

tildeclean:
	/bin/rm *~