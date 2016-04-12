/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:35:36 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/12 19:31:49 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"
#include <stdio.h>


char	*get_hexa_low(va_list *arg, char *buffer, int *tab)
{
	int i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 16);
	return (buffer);
}

char	*get_hexa_up(va_list *arg, char *buffer, int *tab)
{
	int i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 16);
	i = 0;
	while (buffer[i])
	{
		buffer[i] = ft_toupper(buffer[i]);
		i++;
	}
	return (buffer);
}

char	*get_double(va_list *arg, char *buffer, int *tab)
{
	double i;
	double n;

	n = 0.00001;
	i = va_arg((*arg), double);
	buffer = ft_dtoa(i, 6);
	printf("%s\n", buffer);
	printf("%.10f\n", i);
	if (buffer[ft_strlen(buffer) - 1] >= '5')
	{
		printf("Salut\n");
//		i = i + (1 / ft_power(10, 6));
		i += 0.01;
	}
	printf("%.10f\n", i);
	free(buffer);
	buffer = ft_dtoa(i, 5);
	printf("%s\n", buffer);
	return (buffer);
}
