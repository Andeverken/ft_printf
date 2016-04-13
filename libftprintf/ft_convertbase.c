/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 15:33:59 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/13 16:02:23 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	check_value(int i)
{
	if (i < 10)
		return (i + 48);
	if (i == 10)
		return ('a');
	if (i == 11)
		return ('b');
	if (i == 12)
		return ('c');
	if (i == 13)
		return ('d');
	if (i == 14)
		return ('e');
	if (i == 15)
		return ('f');
	return (0);
}

char	*ft_convertbase(int i, int base)
{
	int n;
	int u;
	int y;
	char *str;

	n = 0;
	u = 0;
	y = i;
	while (y >= 1)
	{
		y /= base;
		n++;
	}
	str = (char *) malloc((n + 1) * sizeof(char));
	ft_bzero(str, n + 1);
	while (n--)
	{
		str[u++] = check_value(i / ft_power(base, n));
		i = i % ft_power(base, n);
	}
	return (str);
}
