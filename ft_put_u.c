/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:19:18 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/09 18:19:18 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(unsigned int nb, int i, int j)
{
	j = 0;
	j = ft_put_u(nb / 10);
	if (j == -1)
		return (-1);
	else
		i += j;
	j = 0;
	j = ft_put_u(nb % 10);
	if (j == -1)
		return (-1);
	else
		i += j;
	return (i);
}

int	ft_put_u(unsigned int nb)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	j = 0;
	if (nb >= 10)
	{
		x = helper(nb, i, j);
		if (x == -1)
			return (-1);
		else
			i += x;
	}
	else
	{
		j = 0;
		j = ft_putchar(nb + 48);
		if (j == -1)
			return (-1);
		else
			i += j;
	}
	return (i);
}
