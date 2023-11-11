/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:04:19 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/11 02:13:26 by muel-bak         ###   ########.fr       */
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

int	ft_put_ad(void *ad, char *base)
{
	unsigned long long	nb;
	unsigned long long	len;
	int					i;
	int					j;

	j = 0;
	nb = (unsigned long long)ad;
	len = ft_strlen(base);
	i = 0;
	j = write(1, "0x", 2);
	if (j == -1)
		return (-1);
	else
		i += j;
	j = 0;
	if (nb >= len)
	{
		j = ft_putbase(nb / len, base);
		if (j == -1)
			return (-1);
		else
			i += j;
	}
	j = 0;
	j = ft_putchar(base[nb % len]);
	if (j == -1)
		return (-1);
	else
		i += j;
	return (i);
}
