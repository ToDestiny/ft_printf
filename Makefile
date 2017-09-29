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

NAME = ft_printf
SRC = ft_printf.c \
	  ft_init_struc.c \
	  ft_parse_flags.c \
	  ft_itoa_base.c \


CC = gcc
OBJ = $(SRC:.c=.o)
HEADER = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra
.PHONY : all clean fclean re

all : $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) -I libft $(HEADER)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(HEADER)

clean :
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
