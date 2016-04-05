/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accuracy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:31:16 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/01 19:23:28 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

void		check_accuracy(int *tab, const char *format, int *i)
{
	char str[50];
	int n;

	n = 0;
	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] < '1' || format[*i] > '9')
		{
			tab[1] = 1;
			if (format[*i] == '0')
				(*i)++;
		}
		else
		{
			while (format[*i] >= '1' && format[*i] <= '9')
				str[n++] = format[(*i)++];
			str[n] = 'e';
			tab[2] = ft_atoi(str);
		}
	}
	else if (format[*i] == '*')
		tab[3] = 1;
	else
		tab[0] = 1;
}
