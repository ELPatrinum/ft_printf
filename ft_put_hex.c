/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:25:10 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/10 12:46:43 by muel-bak         ###   ########.fr       */
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

int	ft_put_hex(int nb, char *base)
{
	unsigned long long nbr;
	int			len;
	int			i;

	nbr = (unsigned int)nb;
	len = ft_strlen(base);
	i = 0;
	if (nbr >= len)
	{
		i += ft_putbase(nbr / len, base);
	}
	i += ft_putchar(base[nbr % len]);
	return (i);
}
