/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:35:36 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/13 19:04:15 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

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

	i = va_arg((*arg), double);
	buffer = ft_dtoa(i, 6);
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	return (buffer);
}

char	*get_scient(va_list *arg, char *buffer, int *tab)
{
	double i;
	int		n;

	i = va_arg((*arg), double);
	n = size_forscient(&i);
	buffer = arg_forscient(ft_dtoa(i, 6), n);
	return (buffer);
}
