#ifndef FT_PTINTF_H
# define FT_PTINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_put_u(unsigned int nb);
int	ft_putbase(long long nb, char *base);

#endif