/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 15:33:59 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/04 16:43:22 by rfernand         ###   ########.fr       */
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
	char *str;

	n = 0;
	u = 0;
	while ((i / ft_power(base, n)) >= 1)
		n++;
	str = (char *) malloc(n * sizeof(char));
	while (n--)
	{
		str[u++] = check_value(i / ft_power(base, n));
		i = i % ft_power(base, n);
	}
	return (str);
}
