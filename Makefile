NAME = fillit

SRC = fillit.c validate.c assemble.c make_square.c usage_and_exit.c

HEADER = fillit.h

OBJECT = $(patsubst %.c, %.o, $(SRC))

all:
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -o $(NAME) $(OBJECT)

lldb:
	gcc -g $(SRC)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

tclean:
	/bin/rm -f *~

lldbclean:
	/bin/rm -rf a.out.dSYM
	/bin/rm -f a.out

re: fclean
	make