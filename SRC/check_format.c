/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:32:30 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:16:48 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

int		*alloc_tab(int n)
{
	int *tab;
	int i;

	i = 0;
	tab = (int *)malloc(n * sizeof(int));
	while (i < n)
		tab[i++] = 0;
	return (tab);
}

void	init_tab(int **tab)
{
	tab[0] = alloc_tab(4);
	tab[1] = alloc_tab(1);
	tab[2] = alloc_tab(1);
	tab[3] = alloc_tab(1);
	tab[4] = alloc_tab(2);
}

int		check(char c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == ' ' || c == '#'
			|| c == '.' || c == '*' || c == 'l' || c == 'z' || c == 'L' ||
			(c >= 'b' && c <= 'j') || c == 's' || c == 'o' || c == 'u' ||
			c == 'S' || c == 'O' || c == 'U' || (c >= 'B' && c <= 'G') ||
			c == 'p' || c == '%' || c == 'I' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		is_modif(char c)
{
	if (c == 'h' || c == 'j' || c == 'l' || c == 'z' || c == 'L')
		return (1);
	return (0);
}

int		**check_format(va_list *arg, const char *format, int *i)
{
	int **tab;
	int n;

	*i = *i + 1;
	n = 0;
	tab = (int **)malloc(5 * sizeof(int *));
	init_tab(tab);
	while (!tab[4][0] && format[*i] && check(format[*i]))
	{
		check_flags(tab[0], format, i);
		check_len(arg, tab, format, i);
		if (!n || format[*i] == '.')
			n = check_accuracy(arg, tab, format, i);
		if (is_modif(format[*i]))
			check_modif(tab[3], format, i);
		if (check_type(tab, format[*i]))
			*i = *i + 1;
	}
	if (tab[0][0] != '0' || (tab[2][0] < tab[1][0] && tab[2][0] != -1 &&
				tab[4][0] != 11 && tab[4][0] != 12 && tab[4][0] != 15 &&
				tab[4][0] != 0 && tab[4][0] != 16))
		tab[0][3] = ' ';
	if (!tab[4][0] && format[*i])
		tab[4][1] = format[(*i)++];
	return (tab);
}
