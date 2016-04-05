/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:25:48 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/04 16:00:38 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_int(va_list *arg, char *buffer, int *tab)
{
	int i;

	i = va_arg((*arg), int);
	buffer = ft_itoa(i);
	return (buffer);
}

char	*get_char(va_list *arg, char *buffer, int *tab)
{
	char c;

	c = va_arg((*arg), int);
	buffer = (char *)(malloc(2 * sizeof(char)));
	buffer[0] = c;
	buffer[1] = '\0';
	return (buffer);
}

char	*get_str(va_list *arg, char *buffer, int *tab)
{
	char *str;

	str = va_arg((*arg), char *);
	buffer = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_bzero(buffer, ft_strlen(str) + 1);
	ft_strcpy(buffer, str);
	return (buffer);

}

char	*get_int_ns(va_list *arg, char *buffer, int *tab)
{
	unsigned int i;

	i = va_arg((*arg), unsigned int);
	buffer = ft_utoa(i);
	return (buffer);
}

char	*get_octal(va_list *arg, char *buffer, int *tab)
{
	int i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 8);
	return (buffer);
}
