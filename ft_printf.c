/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:18:59 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/09 18:18:59 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*format == 'i' || *format == 'd')
		return (ft_putbase(va_arg(args, int), "0123456789"));
	else if (*format == 'u')
		return (ft_put_u(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (ft_put_hex(va_arg(args, int), 
				"0123456789abcdef"));
	else if (*format == 'X')
		return (ft_put_hex(va_arg(args, int), 
				"0123456789ABCDEF"));
	else if (*format == 'p')
		return (ft_put_ad(va_arg(args, void *), "0123456789abcdef"));
	else if (*format == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	helper_2(const char *format, va_list args, int counter, int j)
{
	j = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			j = helper(format, args);
			if (j == -1)
				return (-1);
			else
				counter += j;
		}
		else
		{
			j = 0;
			j = ft_putchar(*format);
			if (j == -1)
				return (-1);
			else
				counter += j;
		}
		format++;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		j;

	counter = 0;
	j = 0;
	va_start(args, format);
	j = helper_2(format, args, counter, j);
	if (j == -1)
		return (-1);
	else
		counter += j;
	va_end(args);
	return (counter);
}
