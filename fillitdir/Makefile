#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 12:33:51 by vkeinane          #+#    #+#              #
#    Updated: 2019/11/18 12:40:44 by vkeinane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC =

HEADER = fillit.h

OBJECT = $(patsubst %.c %.o $(SRC))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJECT)
clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean
make