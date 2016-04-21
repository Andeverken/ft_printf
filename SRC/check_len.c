/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:03:27 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/21 16:22:49 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

void	check_len(va_list *arg, int *tab, const char * format, int *i)
{
	char str[200];
	int n;

	n = 0;
	if (format[*i] != '0' && !tab[0])
	{
		while (format[*i] >= '0' && format[*i] <= '9')
			str[n++] = format[(*i)++];
		str[n] = 'e';
		tab[0] = ft_atoi(str);
	}
	else if (format[*i] == '0' && !tab[0])
	{
		(*i)++;
		while (format[*i] >= '0' && format[*i] <= '9')
			str[n++] = format[(*i)++];
		str[n] = 'e';
		tab[0] = ft_atoi(str);
	}
	else if (format[*i] == '*')
	{
		tab[0] = va_arg((*arg), int);
		(*i)++;
	}
}
