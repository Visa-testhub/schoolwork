NAME = fillit

SRC = fillit.c validate.c assemble.c assemble_help.c make_square.c \
		usage_and_exit.c

HEADER = fillit.h

OBJECT = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -o $(NAME) $(OBJECT)

lldb:
	gcc -g $(SRC)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean
	make