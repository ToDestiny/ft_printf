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

NAME = ft_printf.a
SRC = ft_printf.c \
	ft_char.c \
	ft_count_int.c \
	ft_hex.c \
	ft_long.c \
	ft_nbr_lmt.c \
	ft_nbr.c \
	ft_unbr.c \
	ft_str.c \
	ft_nbr_lf.c \
	ft_octal.c \
	ft_putnbr_ld \

CC = gcc
OBJ = $(SRC:.c=.o)
HEADER = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra
INC = ./ft_printf.h

all : $(NAME)

%.o:%.c $(INC)
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re