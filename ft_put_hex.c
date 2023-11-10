/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:25:10 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/10 17:31:46 by muel-bak         ###   ########.fr       */
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
	unsigned long long	nbr;
	int					len;
	int					i;
	int					j;

	j = 0;
	nbr = (unsigned int)nb;
	len = ft_strlen(base);
	i = 0;
	if (nbr >= len)
	{
		j = ft_put_hex(nbr / len, base);
		if (j == -1)
			return (-1);
		else
			i += j;
	}
	j = 0;
	j = ft_putchar(base[nbr % len]);
	if (j == -1)
		return (-1);
	else
		i += j;
	return (i);
}
