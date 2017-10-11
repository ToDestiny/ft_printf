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

NAME = libftprintf.a
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
	ft_putnbr_ld.c \

CC = gcc
OBJ = $(SRC:.c=.o)
HEADER = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra
INC = ./ft_printf.h
RM = rm -f
CLEAN = clean
DIR_LIB	= libft
LIBFT	= $(DIR_LIB)/libft.a

all : $(NAME)

%.o:%.c $(INC)
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(LIBFT):
	@make -C $(DIR_LIB)

clean:
	@make clean -C $(DIR_LIB)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(DIR_LIB) 
	@$(RM) $(NAME) $(HEADER)

re: fclean all

.PHONY : clean fclean re all