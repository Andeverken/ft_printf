/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:58:14 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/12 18:49:23 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_lennb(long n)
{
	int u;

	u = 0;
	if (n < 0)
		u++;
	while (n > 9 || n < -9)
	{
		u++;
		n = n / 10;
	}
	return (u + 1);
}

static char	*negatifvalue(long n)
{
	char	*str;
	int		u;
	int		h;

	u = ft_lennb(n);
	h = u;
	str = (void *)malloc((u + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (u--)
	{
		str[u] = -(n % 10) + 48;
		n = n / 10;
	}
	str[0] = '-';
	str[h] = '\0';
	return (str);
}

char		*ft_itoa(long n)
{
	char	*str;
	long		i;
	int		u;
	int		h;

	i = n;
	u = ft_lennb(n);
	h = u;
	if (n < 0)
		return (negatifvalue(n));
	str = (void *)malloc((u + 1) * sizeof(char));
	while (u--)
	{
		str[u] = n % 10 + 48;
		n = n / 10;
	}
	str[h] = '\0';
	return (str);
}
