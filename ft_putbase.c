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

static int	little_helper(long long nb, int len, char *base, int i)
{
	int	j;

	j = 0;
	if (nb < 0)
	{
		nb = -nb;
		if (write(1, "-", 1) < 0)
			return (-1);
		else
			i += 1;
	}
	if (nb >= len)
	{
		j = ft_putbase(nb / len, base);
		if (j < 0)
			return (-1);
		else
			i += j;
	}
	j = ft_putchar(base[nb % len]);
	if (j < 0)
		return (-1);
	else
		i += j;
	return (i);
}

int	ft_putbase(long long nb, char *base)
{
	int			len;
	int			i;
	int			j;

	j = 0;
	len = ft_strlen(base);
	i = 0;
	j = little_helper(nb, len, base, i);
	if (j == -1)
		return (-1);
	else
		i += j;
	return (i);
}
