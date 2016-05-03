/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accuracy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:31:16 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:32:12 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

static void	get_accurary(int **tab, const char *format, int *i)
{
	int		n;
	char	str[50];

	n = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
		str[n++] = format[(*i)++];
	str[n] = 'e';
	tab[2][0] = ft_atoi(str);
}

int			check_accuracy(va_list *arg, int **tab, const char *format, int *i)
{
	char	str[50];
	int		n;

	n = 0;
	if (format[*i] == '.')
	{
		(*i)++;
		if ((format[*i] < '0' || format[*i] > '9') && format[*i] != '*')
			tab[2][0] = 0;
		else if (format[*i] == '*')
		{
			tab[2][0] = va_arg((*arg), int);
			if (tab[2][0] < 0)
				tab[2][0] = -1;
			(*i)++;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
			get_accurary(tab, format, i);
		return (1);
	}
	tab[2][0] = -1;
	return (0);
}
