/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diez_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:32:10 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/20 21:02:49 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*apply_diez_binary(char *tmp, char *buffer, int **tab)
{
	tmp[0] = '0';
	tmp[1] = 'b';
	return (buffer);
}

char		*apply_diez_shorter_low2(char *tmp, char *buffer, int **tab)
{
	char	str[tab[2][0] + 2];
	int		i;

	i = 0;
	ft_strcpy(str, buffer);
	if (!ft_strchr(str, '.'))
		str[ft_strlen(str)] = '.';
	i = ft_strlen(str) + 1;
	while (i <= tab[2][0])
		str[i++] = '0';
	free(buffer);
	buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_bzero(buffer, ft_strlen(str) + 1);
	ft_strcpy(buffer, str);
	return(buffer);
}

char		*apply_diez_shorter_low(char *tmp, char *buffer, int **tab)
{
	char		str[tab[2][0] + 2];
	int			i;

	i = 0;
	ft_bzero(str, tab[2][0] + 2);
	if (ft_strchr(buffer, 'e'))
	{
		while (buffer[i] != 'e')
		{
			str[i] = buffer[i];
			i++;
		}
		ft_memmove(buffer, buffer + i, ft_strlen(buffer) - i);
		ft_bzero(buffer + 4, ft_strlen(buffer) - 4);
		while (i <= tab[2][0])
			str[i++] = '0';
		ft_strcat(str, buffer);
		free(buffer);
		buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
		ft_bzero(buffer, ft_strlen(str) + 1);
		ft_strcpy(buffer, str);
		return(buffer);
	}
	else
		return(apply_diez_shorter_low2(tmp, buffer, tab));
}
