#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 11:01:59 by vkeinane          #+#    #+#              #
#    Updated: 2020/09/17 13:19:50 by vkeinane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_putchar.c ft_putstr.c ft_strlen.c ft_strcpy.c ft_strncpy.c \
		ft_putendl.c ft_strdup.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_isalpha.c ft_strcmp.c \
		ft_strncmp.c ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcat.c \
		ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
		ft_strnstr.c ft_strclr.c ft_strequ.c ft_strnequ.c ft_memalloc.c \
		ft_memdel.c ft_strnew.c ft_strdel.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		ft_strsplit.c ft_itoa.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c ft_wrdcnt.c ft_lstpb.c \
		ft_crealloc.c ft_abs.c ft_atoi_base.c ft_iswhitespace.c

HEADER = libft.h

OBJECT = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJECT)
clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
