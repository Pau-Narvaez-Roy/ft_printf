/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarvaez <pnarvaez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 09:45:36 by pnarvaez          #+#    #+#             */
/*   Updated: 2026/06/16 12:09:48 by pnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("valor: %i\n", ft_printf("hola%i%i%i %s %u %X\n", 1, 2, 3, "adios", 2147483648, 2147483648));
	printf("\n");
	printf("valor: %i\n", printf("hola%i%i%i %s %u %X\n", 1, 2, 3, "adios", 2147483648, 2147483648));
	printf("\n");
	printf("\n\n");
	//ft_printf("%d\n", ft_printf(NULL));
	printf("%d\n", printf(NULL));
	return (0);
}