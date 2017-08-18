# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 14:42:35 by acolas            #+#    #+#              #
#    Updated: 2017/08/18 15:17:19 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c \

CC = gcc
OBJ = $(SRC:.c=.o)
HEADER =
CFLAGS = -Wall -Werror -Wextra
.PHONY : all clean fclean re

all : $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(HEADER)

$(NAME) : $(OBJ)
	@make -C $(NAME)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(HEADER)

clean :
	@make -C $(NAME) clean
	@/bin/rm -rf $(OBJ)

fclean : clean
	@make -C $(NAME) fclean
	@/bin/rm -rf $(NAME)

re : fclean all
