/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:32:59 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/01 19:24:12 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

void	check_type_2(int **tab, char c)
{
	if (c == 'g')
		tab[4][0] = 9;
	if (c == 'G')
		tab[4][0] = 10;
	if (c == 'c')
		tab[4][0] = 11;
	if (c == 's')
		tab[4][0] = 12;
	if (c == 'p')
		tab[4][0] = 13;
}

int		check_type(int **tab, char c)
{
	if (c == 'd' || c == 'i')
		tab[4][0] = 1;
	if (c == 'o')
		tab[4][0] = 2;
	if (c == 'u')
		tab[4][0] = 3;
	if (c == 'x')
		tab[4][0] = 4;
	if (c == 'X')
		tab[4][0] = 5;
	if (c == 'f')
		tab[4][0] = 6;
	if (c == 'e')
		tab[4][0] = 7;
	if (c == 'E')
		tab[4][0] = 8;
	check_type_2(tab, c);
	if (tab[4][0])
		return (1);
	return (0);
}
