SRC = ft_printf.c ft_put_u.c ft_putbase.c ft_putchar.c ft_putstr.c

OBJ = $(SRC:.c=.o);

NAME = libftprintf.a

all: $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all