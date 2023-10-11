#include "ft_printf.h"

int	ft_put_u(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
	{
		i += ft_put_u(nb / 10);
		i += ft_put_u(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}