/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:56:49 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/13 17:43:49 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

static char		*ft_resize_round(char *str)
{
	char buffer[ft_strlen(str) + 2];

	ft_bzero(buffer, ft_strlen(str) + 2);
	buffer[0] = '1';
	ft_strcat(buffer, str);
	free(str);
	str = (char*) malloc((ft_strlen(buffer) + 1) * sizeof(char));
	ft_strcpy(str, buffer);
	return (str);
}

char			*ft_round(char *str, int size)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] <= '5')
		str[i] = '\0';
	else
	{
		size--;
		if (str[size] == '.')
			size--;
		if (str[size] == '9')
		{
			ft_round(str, size);
			str[size] = '0';
		}
		else
		{
			if (size >= 0)
				str[size] = str[size] +1;
		}
		str[i] = '\0';
	}
	if (str[0] == '0' && size == ft_strlen(str) - 1)
		str = ft_resize_round(str);
	return (str);
}
