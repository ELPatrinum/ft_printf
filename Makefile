# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 18:19:42 by muel-bak          #+#    #+#              #
#    Updated: 2023/11/09 18:19:42 by muel-bak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_put_u.c ft_putbase.c ft_putchar.c ft_putstr.c ft_put_ad.c ft_put_hex.c 

OBJ = $(SRC:.c=.o);

NAME = libftprintf.a

all: $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
