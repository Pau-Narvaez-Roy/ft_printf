/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarvaez <pnarvaez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 08:23:12 by pnarvaez          #+#    #+#             */
/*   Updated: 2026/06/22 14:04:16 by pnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"	

static int	ft_print_vargs(char const *format, va_list vargs)
{
	int	count_printed;

	count_printed = 0;
	if (*format == 'c')
		count_printed += ft_putchar(va_arg(vargs, int));
	else if (*format == 's')
		count_printed += ft_putstr(va_arg(vargs, char *));
	else if (*format == 'p')
		count_printed += ft_putnbr_long_base(va_arg(vargs, void *));
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
	else
		count_printed--;
	return (count_printed);
}

int	ft_choose_format(char const *format, va_list vargs)
{
	int				count_printed;
	int				temp;

	count_printed = 0;
	while (*format)
	{
		temp = count_printed;
		if (*format == '%' && *(format + 1))
		{
			count_printed += ft_print_vargs(format + 1, vargs);
			if (count_printed < temp)
				count_printed += ft_putchar((char) *format);
			else
				format++;
		}
		else
			count_printed += ft_putchar((char) *format);
		format++;
	}
	return (count_printed);
}

int	ft_printf(char const *format, ...)
{
	va_list			vargs;
	int				count_printed;

	if (!format)
		return (-1);
	va_start(vargs, format);
	count_printed = ft_choose_format(format, vargs);
	va_end(vargs);
	return (count_printed);
}
