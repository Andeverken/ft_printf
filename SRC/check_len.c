/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:03:27 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/02 16:05:18 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

void	check_len(int *tab, const char * format, int *i)
{
	char str[50];
	int n;

	n = 0;
	if (format[*i] != '0')
		{
			while (format[*i] >= '0' && format[*i] <= '9')
				str[n++] = format[(*i)++];
			str[n] = 'e';
			tab[0] = ft_atoi(str);
		}
	else if (format[*i] == '0')
	{
		(*i)++;
		while (format[*i] >= '0' && format[*i] <= '9')
			str[n++] = format[(*i)++];
		str[n] = 'e';
		tab[1] = ft_atoi(str);
	}
	else if (format[*i] == '*')
	{
		tab[2] = 1;
		(*i)++;
	}
}
