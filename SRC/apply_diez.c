/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diez.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:30:16 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/25 19:08:18 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*apply_diez_octal(char *tmp, char *buffer, int **tab)
{
	if (buffer[0] == '0')
		return (buffer);
	tmp[0] = '0';
	return(buffer);
}

char		*apply_diez_hexa_low(char *tmp, char *buffer, int **tab)
{
	if (buffer[0] == '0' || !tab[2][0])
		return (buffer);
	tmp[0] = '0';
	tmp[1] = 'x';
	return(buffer);
}

char		*apply_diez_hexa_up(char *tmp, char *buffer, int **tab)
{
	if (buffer[0] == '0' || !tab[2][0])
		return (buffer);
	tmp[0] = '0';
	tmp[1] = 'X';
	return(buffer);
}

char		*apply_diez_double(char *tmp, char *buffer, int **tab)
{
	char	str[ft_strlen(buffer) + 2];

	if (ft_strchr(buffer, '.'))
		return(buffer);
	ft_bzero(str, ft_strlen(buffer) + 2);
	ft_strcpy(str, buffer);
	str[ft_strlen(str)] = '.';
	free(buffer);
	buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_bzero(buffer, ft_strlen(str) + 1);
	ft_strcpy(buffer, str);
	return(buffer);
}

char		*apply_diez_scient_low(char *tmp, char *buffer, int **tab)
{
	char	str[ft_strlen(buffer) + 2];

	if (ft_strchr(buffer, '.'))
		return(buffer);
	ft_bzero(str, ft_strlen(buffer) + 2);
	str[0] = buffer[0];
	str[1] = '.';
	ft_memmove(buffer, buffer + 1, ft_strlen(buffer));
	ft_strcat(str, buffer);
	free(buffer);
	buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_bzero(buffer, ft_strlen(str) + 1);
	ft_strcpy(buffer, str);
	return(buffer);
}
