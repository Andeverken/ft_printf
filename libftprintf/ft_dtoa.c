/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:42:00 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:47:11 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_dtoa(long double i, int size)
{
	long int	n;
	int			u;
	char		*str;
	char		*buffer;

	n = (long int)i;
	buffer = ft_itoa(n);
	str = (char *)malloc((ft_strlen(buffer) + size + 3) * sizeof(char));
	ft_bzero(str, ft_strlen(buffer) + size + 3);
	ft_strcpy(str, buffer);
	free(buffer);
	u = ft_strlen(str);
	if (size > 0)
		str[u++] = '.';
	i = i - (long double)n;
	if (i < 0)
		i = -i;
	while (size-- + 1)
	{
		i = 10 * i;
		n = (int)i;
		str[u++] = n + '0';
		i = i - (long double)n;
	}
	return (str);
}
