/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarvaez <pnarvaez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:17:01 by pnarvaez          #+#    #+#             */
/*   Updated: 2026/06/22 14:18:56 by pnarvaez         ###   ########.fr       */
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
	write(1, &base[nb % 16], 1);
	count++;
	return (count);
}

int	ft_putnbr_long_base(void *nb)
{
	int				count;
	unsigned long	nbr;

	if (!nb)
	{
		write(1, "(nil)", 5);
		count = 5;
	}
	else
	{
		write(1, "0x", 2);
		count = 2;
		nbr = (unsigned long) nb;
		count += ft_putnbr_long_base_rec((unsigned long) nbr);
	}
	return (count);
}

int	ft_putnbr_base(unsigned int nb, int pos)
{
	char	**base;
	int		count;

	base = (char **) malloc(sizeof(char *) * 3);
	base[0] = "0123456789abcdef";
	base[1] = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
		count += ft_putnbr_base(nb / 16, pos);
	write(1, &base[pos][nb % 16], 1);
	free(base);
	count++;
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	res;
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	res = n % 10;
	res = res + '0';
	write(1, &res, 1);
	count++;
	return (count);
}

int	ft_putnbr(int n)
{
	int	res;
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	res = n % 10;
	res = res + '0';
	write(1, &res, 1);
	count++;
	return (count);
}
