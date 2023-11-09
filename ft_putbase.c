/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:19:28 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/09 18:19:28 by muel-bak         ###   ########.fr       */
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

int	ft_putbase(long long nb, char *base)
{
	int			len;
	int			i;

	len = ft_strlen(base);
	i = 0;
	if (nb == (-9223372036854775807 - 1))
	{
		return(write(1, "-9223372036854775808", 19));
	}
	if (nb < 0)
	{
		nb = -nb;
		i += write(1, "-", 1);
	}
	if (nb >= len)
	{
		i += ft_putbase(nb / len, base);
	}
	i += ft_putchar(base[nb % len]);
	return (i);
}
