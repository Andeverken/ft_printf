/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:56:49 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/13 17:32:53 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"
#include <stdio.h>

static char		*ft_resize_round(char *str)
{
	char buffer[ft_strlen(str) + 2];

	printf("%s\n", str);
	ft_bzero(buffer, ft_strlen(str) + 2);
	buffer[0] = '1';
	ft_strcat(buffer, str);
	printf("%s\n", buffer);
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

int		main(void)
{
	char *str;

	str = malloc (12 * sizeof(char));
	ft_bzero(str, 12);
	ft_strcpy(str, "999.9999997");
	printf("%s\n", ft_round(str, ft_strlen(str) - 1));
}
