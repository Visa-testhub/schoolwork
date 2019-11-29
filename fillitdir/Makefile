NAME = fillit

SRC = fillit.c validate.c assemble.c usage_and_exit.c

HEADER = fillit.h

OBJECT = $(patsubst %.c, %.o, $(SRC))

all:
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -o $(NAME) $(OBJECT) -I libft/ libft/libft.a

lldb:
	gcc -g $(SRC) -I libft/ libft/libft.a

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

tclean:
	/bin/rm -f *~

re: fclean
	make