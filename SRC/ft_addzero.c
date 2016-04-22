/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 14:53:50 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/22 17:40:11 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*ft_addzero(char *str, int size)
{
	int i;
	int n;
	char buf[size + 1];

	ft_bzero(buf, size + 1);
	n = 0;
	if (str[0] == '0' && size == 0)
		str[0] = '\0';
	else if ((i = ft_strlen(str)) <= size)
	{
		if (str[0] == '-')
		{
			buf[n++] = '-';
			ft_memmove(str, str + 1, ft_strlen(str));
			i--;
		}
		while (i++ < size)
			buf[n++] = '0';
		ft_strcat(buf, str);
		free(str);
		str = (char*) malloc((size + 2) * sizeof(char));
		ft_bzero(str, size + 1);
		ft_strcpy(str, buf);
	}
	return (str);
}
