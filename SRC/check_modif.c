/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:55:18 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/16 14:58:34 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_modif(int *tab, const char *format, int *i)
{
	if (format[(*i)] == 'h' && tab[0] < 3)
	{
		if (format[(*i) + 1] == 'h' && tab[0] < 2)
			tab[0] = 1;
		else
			tab[0] = 2;
	}
	else if (format[(*i)] == 'l')
	{
		if (format[(*i) + 1] == 'l')
			tab[0] = 4;
		else if (tab[0] < 4)
			tab[0] = 3;
	}
	else if (format[(*i)] == 'j' && tab[0] != 4 && tab[0] != 6)
		tab[0] = 5;
	else if (format[(*i)] == 'z' && tab[0] != 4)
		tab[0] = 6;
	else if (format[(*i)] == 'L')
		tab[0] = 7;
	if (tab[0])
		(*i)++;
	if (tab[0] == 1 || tab[0] == 4)
		(*i)++;
}
