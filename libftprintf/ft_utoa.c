/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:48:37 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/01 19:53:24 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_lennb(unsigned int n)
{
	int u;

	u = 0;
	while (n > 9)
	{
		u++;
		n = n / 10;
	}
	return (u + 1);
}

char		*ft_utoa(unsigned int n)
{
	char	*str;
	unsigned int		i;
	int		u;
	int		h;

	i = n;
	u = ft_lennb(n);
	h = u;
	str = (char *)malloc((u + 1) * sizeof(char));
	while (u--)
	{
		str[u] = n % 10 + 48;
		n = n / 10;
	}
	str[h] = '\0';
	return (str);
}
