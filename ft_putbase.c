#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putbase(long long nb, char *base)
{
	int	len;
	int	i;

	len = ft_strlen(base);
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i += write(1, "-",  1);
	}
	if (nb >= len)
	{
		i += ft_putbase(nb / len, base);
	}
	i += ft_putchar(base[nb % len]);
	return (i);
}