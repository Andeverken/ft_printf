/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:55:18 by rfernand          #+#    #+#             */
/*   Updated: 2016/03/25 15:57:49 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_modif(int *tab, char c)
{
	if (c == 'h')
		tab[0] = 'h';
	else if (c == 'l')
		tab[0] = 'l';
	else if (c == 'L')
		tab[0] = 'L';
	else
		return (0);
	return (1);
}
