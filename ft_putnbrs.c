/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarvaez <pnarvaez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:17:01 by pnarvaez          #+#    #+#             */
/*   Updated: 2026/08/05 12:59:34 by pnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_long_base_rec(unsigned long nb)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count += ft_putnbr_long_base_rec(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_putnbr_long_base(void *nb)
{
	int				count;

	if (!nb)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_putnbr_long_base_rec((unsigned long) nb);
	return (count);
}

int	ft_putnbr_base(unsigned int nb, int pos)
{
	char	*base[2];
	int		count;

	base[0] = "0123456789abcdef";
	base[1] = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
		count += ft_putnbr_base(nb / 16, pos);
	count += ft_putchar(base[pos][nb % 16]);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	res;
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	res = n % 10;
	res = res + '0';
	count += ft_putchar(res);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	count += ft_putnbr_unsigned(n);
	return (count);
}
