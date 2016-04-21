/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:38:52 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/20 18:39:50 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_int_max(va_list *arg, char *buffer, int **tab)
{
	intmax_t i;

	i = va_arg((*arg), intmax_t);
	buffer = ft_itoa(i);
	return (buffer);
}

char	*get_size_int(va_list *arg, char *buffer, int **tab)
{
	size_t i;

	i = va_arg((*arg), size_t);
	buffer = ft_itoa(i);
	return (buffer);
}
