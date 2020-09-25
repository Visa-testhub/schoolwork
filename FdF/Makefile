# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 14:06:39 by vkeinane          #+#    #+#              #
#    Updated: 2020/09/24 11:56:00 by vkeinane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c key_press.c ft_shutdown.c map_reader.c draw_menu.c\
	  draw_map.c draw_image.c free_utils.c draw_utils.c

HEADER = fdf.h

OBJECT = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

LINKS = -I ./libft \
 -L ./libft -lft \
 -I /usr/local/lib/minilibx \
 -L /usr/local/lib -lmlx \
 -I /usr/local/include/X11/ \
 -L /usr/X11/lib -lX11 -lXext \
 -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(SRC) $(FLAGS) $(LINKS)

lldb:
	gcc -g -o fdflldb $(SRC) $(FLAGS) $(LINKS)

clean:
	make clean -C libft/
	/bin/rm -f $(OBJECT)

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

lldbclean:
	/bin/rm -f fdflldb
	/bin/rm -r fdflldb.dSYM

re: fclean all
