/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:32:30 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/13 16:46:16 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

int		*alloc_tab(int n)
{
	int *tab;
	int i;

	i = 0;
	tab = (int *) malloc(n * sizeof(int));
	while (i < n)
		tab[i++] = 0;
	return (tab);
}

void	init_tab(int **tab)
{
	tab[0] = alloc_tab(5);
	tab[1] = alloc_tab(3);
	tab[2] = alloc_tab(4);
	tab[3] = alloc_tab(1);
	tab[4] = alloc_tab(1);
}

int		**check_format(const char *format, int *i)
{
	int **tab;

	*i = *i + 1;
	tab = (int **) malloc(5 * sizeof(int *));
	init_tab(tab);
	check_flags(tab[0], format, i);
	check_len(tab[1], format, i);
	check_accuracy(tab[2], format, i);
	check_modif(tab[3], format, i);
	if (check_type(tab, format[*i]))
		*i = *i + 1;
	return (tab);
}
