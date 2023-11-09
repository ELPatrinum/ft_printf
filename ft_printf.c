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
		return (ft_putbase(va_arg(args, long long), "0123456789abcdef"));
	else if (*format == 'X')
		return (ft_putbase(va_arg(args, long long), "0123456789ABCDEF"));
	else if (*format == 'p')
		return (ft_put_ad(va_arg(args, void *)));
	else if (*format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			counter += helper(format, args);
		}
		else
			counter += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (counter);
}
