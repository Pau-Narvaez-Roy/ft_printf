/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarvaez <pnarvaez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 09:45:36 by pnarvaez          #+#    #+#             */
/*   Updated: 2026/06/22 14:19:15 by pnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf("valor: %i\n", ft_printf("1:%p,%p\n", ULONG_MAX, -ULONG_MAX));
	printf("valor: %i\n", printf("2:%p,%p\n", ULONG_MAX, -ULONG_MAX));
	/*ft_printf("valor: %i\n", ft_printf("1:%s\n", NULL));
	printf("valor: %i\n", printf("2:%s\n", NULL));
	ft_printf("\n");
	ft_printf("valor: %i\n", ft_printf("1:%%%\n"));
	printf("valor: %i\n", printf("2:%%%\n"));
	ft_putstr("HOLA");
	ft_printf("valor: %i\n", ft_printf("hola%i%i%i %s %u %X\n", 1, 2, 3, "adios", 2147483648, 2147483648));
	ft_printf("\n");
	printf("valor: %i\n", printf("hola%i%i%i %s %u %X\n", 1, 2, 3, "adios", 2147483648, 2147483648));
	ft_printf("\n");
	ft_printf("valor: %i\n", ft_printf("1:%k\n"));
	printf("valor: %i\n", printf("2:%k\n"));
	ft_printf("\n");
	ft_printf("valor: %i\n", ft_printf("1:%i\n"));
	printf("valor: %i\n", printf("2:%i\n"));
	ft_printf("\n");
	ft_printf("valor: %i\n", ft_printf("1:\n"));
	printf("valor: %i\n", printf("2:\n"));
	ft_printf("\n");
	ft_printf("valor: %i\n", ft_printf("1:\n", NULL));
	printf("valor: %i\n", printf("2:\n", NULL));
	ft_printf("\n");
	ft_printf("valor: %i\n", ft_printf("1:%s\n", "aaa"));
	printf("valor: %i\n", printf("2:%s\n", "aaa"));
	ft_printf("\n");
	ft_printf("valor: %i\n", ft_printf("1:%j%\n"));
	printf("valor: %i\n", printf("2:%j%\n"));
	ft_printf("\n");
	ft_printf("valor: %i\n", ft_printf("1:%\n"));
	printf("valor: %i\n", printf("2:%\n"));*/
	return (0);
}
