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
SRC_DIR = ./src/
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
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
DIR_LIB	= libft
LIBFT	= $(DIR_LIB)/libft.a

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(CFLAGS) -c $(addprefix $(SRC_DIR)/,$(SRC))
	@ar -rc $(NAME) $(OBJ) ./libft/*.o

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