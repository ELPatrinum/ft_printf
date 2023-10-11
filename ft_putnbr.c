#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			i++;
			write(1, "-", 1);
		}
		if (nb >= 10)
		{
			i += ft_putnbr(nb / 10);
			i += ft_putnbr(nb % 10);
		}
		else
			i += ft_putchar(nb + 48);
	}
	return (i);
}