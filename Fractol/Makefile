# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/28 18:38:40 by vkeinane          #+#    #+#              #
#    Updated: 2020/10/15 13:06:45 by vkeinane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c shutdown.c deal_key.c deal_mouse.c \
	  draw.c draw_image.c draw_utils.c

HEADER = fractol.h

OBJECT = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

LINKS = -I ./libft \
 -L ./libft -lft \
 -I ./Minilibx \
 -L ./Minilibx -lmlx \
 -I /usr/local/include/X11/ \
 -L /usr/X11/lib -lX11 -lXext \
 -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	make -C libft/
	make -C Minilibx/
	gcc -o $(NAME) $(SRC) $(FLAGS) $(LINKS)

lldb:
	gcc -g -o debugging  $(SRC) $(FLAGS) $(LINKS)

clean:
	make clean -C libft/
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

lldbclean:
	/bin/rm -f debugging
	/bin/rm -r debugging.dSYM

re: fclean all
