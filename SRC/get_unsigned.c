/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:03:18 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/20 19:26:35 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_normal_unsigned(va_list *arg, char *buffer, int **tab, int base)
{
	unsigned int i;

	i = va_arg((*arg), unsigned int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_short_short_unsigned(va_list *arg, char *buffer, int **tab,
		int base)
{
	unsigned char i;

	i = va_arg((*arg), unsigned int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_short_unsigned(va_list *arg, char *buffer, int **tab, int base)
{
	unsigned short int i;

	i = va_arg((*arg), unsigned int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_long_unsigned(va_list *arg, char *buffer, int **tab, int base)
{
	unsigned long int i;

	i = va_arg((*arg), unsigned long int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_long_long_unsigned(va_list *arg, char *buffer, int **tab, int base)
{
	unsigned long long int i;

	i = va_arg((*arg), unsigned long long int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}
