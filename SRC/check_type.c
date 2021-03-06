/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:32:59 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/29 12:30:29 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

void	check_type_3(int **tab, char c)
{
	if (c == 'X')
		tab[4][0] = 5;
	if (c == 'f' || c == 'F')
		tab[4][0] = 6;
	if (c == 'e')
		tab[4][0] = 7;
	if (c == 'E')
		tab[4][0] = 8;
}

void	check_type_2(int **tab, char c)
{
	if (c == 'g')
		tab[4][0] = 9;
	if (c == 'G')
		tab[4][0] = 10;
	if (c == 'c' || c == 'C')
	{
		tab[4][0] = 11;
		if (c == 'C')
			tab[3][0] = 3;
	}
	if (c == 's')
		tab[4][0] = 12;
	if (c == 'p')
		tab[4][0] = 13;
	if (c == 'b' || c == 'B')
		tab[4][0] = 14;
	if (c == '%')
		tab[4][0] = 15;
	if (c == 'x')
		tab[4][0] = 4;
	check_type_3(tab, c);
}

int		check_type(int **tab, char c)
{
	if (c == 'd' || c == 'i' || c == 'D' || c == 'I')
	{
		tab[4][0] = 1;
		if (c == 'D' || c == 'I')
			tab[3][0] = 3;
	}
	if (c == 'o' || c == 'O')
	{
		tab[4][0] = 2;
		if (c == 'O')
			tab[3][0] = 3;
	}
	if (c == 'u' || c == 'U')
	{
		tab[4][0] = 3;
		if (c == 'U')
			tab[3][0] = 3;
	}
	if (c == 'S')
		tab[4][0] = 16;
	check_type_2(tab, c);
	if (tab[4][0])
		return (1);
	return (0);
}
