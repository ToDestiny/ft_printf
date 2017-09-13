# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 14:42:35 by acolas            #+#    #+#              #
#    Updated: 2017/09/13 15:40:48 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
SRC = ft_printf.c \
	  ft_init_struc.c \
	  ft_parse_flags.c \

CC = gcc
OBJ = $(SRC:.c=.o)
HEADER = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra
.PHONY : all clean fclean re

all : $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) -I libft $(HEADER)

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
