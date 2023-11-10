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

int	ft_put_u(unsigned int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (nb >= 10)
	{
		j = ft_put_u(nb / 10);
		if (j == -1)
			return (-1);
		else
			i += j;
		j = ft_put_u(nb % 10);
		if (j == -1)
			return (-1);
		else
			i += j;
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
