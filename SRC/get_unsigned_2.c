/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:06:39 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/20 19:36:12 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_unsigned_max(va_list *arg, char *buffer, int **tab, int base)
{
	uintmax_t i;

	i = va_arg((*arg), uintmax_t);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_size_unsigned(va_list *arg, char *buffer, int **tab, int base)
{
	size_t i;

	i = va_arg((*arg), size_t);
	buffer = ft_convertbase(i, base);
	return (buffer);
}
