/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarvaez <pnarvaez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 08:23:12 by pnarvaez          #+#    #+#             */
/*   Updated: 2026/06/16 11:58:00 by pnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"	

int	ft_look_type(char const *format, va_list vargs)
{
	int	count_printed;

	count_printed = 0;
	if (*format == 'c')
		count_printed += ft_putchar(va_arg(vargs, int));
	else if (*format == 's')
		count_printed += ft_putstr(va_arg(vargs, char *));
	else if (*format == 'p')
		count_printed += ft_putnbr_long_base(va_arg(vargs, long));
	else if (*format == 'd')
		count_printed += ft_putnbr(va_arg(vargs, int));
	else if (*format == 'i')
		count_printed += ft_putnbr(va_arg(vargs, int));
	else if (*format == 'u')
		count_printed += ft_putnbr_unsigned(va_arg(vargs, unsigned int));
	else if (*format == 'x')
		count_printed += ft_putnbr_base(va_arg(vargs, unsigned int), 0);
	else if (*format == 'X')
		count_printed += ft_putnbr_base(va_arg(vargs, unsigned int), 1);
	else if (*format == '%')
		count_printed += ft_putchar('%');
	return (count_printed);
}

int	ft_printf(char const *format, ...)
{
	va_list			vargs;
	int				count_printed;

	va_start(vargs, format);
	count_printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count_printed += ft_look_type(format, vargs);
		}
		else
		{
			ft_putchar((char) *format);
			count_printed++;
		}
		format++;
	}
	va_end(vargs);
	return (count_printed);
}
