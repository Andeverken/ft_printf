/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:03:27 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/26 17:42:10 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

void	check_len(va_list *arg, int **tab, const char *format, int *i)
{
	char str[200];
	int n;

	n = 0;
	if (format[*i] != '0' && format[*i] != '*')
	{
		while (format[*i] >= '0' && format[*i] <= '9')
			str[n++] = format[(*i)++];
		str[n] = 'e';
		if (ft_atoi(str) || !tab[1][0])
			tab[1][0] = ft_atoi(str);
	}
	else if (format[*i] == '0' && !tab[0])
	{
		(*i)++;
		while (format[*i] >= '0' && format[*i] <= '9')
			str[n++] = format[(*i)++];
		str[n] = 'e';
	}
	else if (format[*i] == '*')
	{
		tab[1][0] = va_arg((*arg), int);
		if (tab[1][0] < 0)
		{
			tab[0][0] = '-';
			tab[1][0] = -tab[1][0];
		}
		(*i)++;
	}
}
