/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:32:00 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/25 19:03:32 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*fill_point(char *buffer, int **tab)
{
	char	tmp[15];
	int		i;
	int		n;

	n = 3;
	ft_bzero(tmp, 15);
	i = ft_strlen(buffer);
	tmp[0] = '0';
	tmp[1] = 'x';
/*	if (i++ < 12 && buffer[0] != '0')
	{
		tmp[2] = '7';
		while (i++ < 12)
			tmp[n++] = 'f';
	}
*/	if (buffer[0] != '0' || tab[2][0] >= 1)
		ft_strcat(tmp, buffer);
	free(buffer);
	buffer = (char *)malloc(15 * sizeof(char));
	ft_bzero(buffer, 15);
	ft_strcpy(buffer, tmp);
	return (buffer);
}

void		ft_delete_zero(char *str)
{
	int a;

	a = ft_strlen(str) - 1;
	while (str[a] == '0')
			str[a--] = '\0';
	if (str[a] == '.')
		str[a] = '\0';
}
