/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:04:19 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/09 20:02:22 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_put_ad(void *ad)
{
	unsigned long long	nb;
	int			len;
	int			i;
	char		*base;

	base = "0123456789abcdef";
	nb = (unsigned long long)ad;
	len = ft_strlen(base);
	i = 0;
	i += write(1, "0x", 2); // Print "0x" for pointer address
	if (nb >= len)
	{
		i += ft_putbase(nb / len, base);
	}
	i += ft_putchar(base[nb % len]);
	return (i);
}

