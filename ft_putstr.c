/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:19:38 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/09 18:19:38 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == NULL)
	{
		j = write(1, "(null)", 6);
		if (j == -1)
			return (-1);
		else
			return (j);
	}
	while (str[i])
	{
		j = write(1, &str[i], 1);
		if (j == -1)
			return (-1);
		else
			i += j;
	}
	return (i);
}
