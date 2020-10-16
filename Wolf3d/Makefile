# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/28 18:38:40 by vkeinane          #+#    #+#              #
#    Updated: 2020/10/16 12:01:08 by vkeinane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = src/wolf3d.c src/read.c src/validate_map.c src/deal_key.c src/draw.c \
	  src/cast_rays.c src/ray_movement.c src/draw_utils.c src/minimap.c \
	  src/textures.c src/shutdown.c

HEADER = wolf3d.h

OBJECT = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

LINKS = -I . \
 -I ./libft \
 -L ./libft -lft \
 -I ./minilibx \
 -L ./minilibx -lmlx \
 -I /usr/local/include/X11/ \
 -L /usr/X11/lib -lX11 -lXext \
 -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	make -C libft/
	make -C minilibx/
	gcc -o $(NAME) $(SRC) $(FLAGS) $(LINKS)

lldb:
	gcc -g -o debugging  $(SRC) $(FLAGS) $(LINKS) $(HEADER)

clean:
	make clean -C libft/
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

lldbclean:
	/bin/rm -f debugging
	/bin/rm -r debugging.dSYM

re: fclean all
