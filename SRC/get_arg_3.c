/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:31:41 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/27 17:35:03 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*get_point(va_list *arg, char *buffer, int **tab)
{
	long		i;

	if (tab[2][0] == -1)
		tab[2][0] = 1;
	i = va_arg((*arg), long);
	buffer = ft_convertbase(i, 16);
	buffer = ft_addzero(buffer, tab[2][0]);
	buffer = fill_point(buffer, tab);
	return (buffer);
}

char		*get_shorter(va_list *arg, char *buffer, int **tab)
{
	double	i;
	int		n;
	double	y;
	int		a;

	if (tab[2][0] == -1)
		tab[2][0] = 6;
	n = 0;
	i = va_arg((*arg), double);
	y = i;
	if (y)
		n = size_forscient(&y);
	if (n > tab[2][0] - 1)
	{
		buffer = ft_dtoa(y, tab[2][0] - 1);
		if (ft_strlen(buffer) > 2)
			buffer = ft_round(buffer, ft_strlen(buffer) - 1);
		ft_delete_zero(buffer);
		buffer = arg_forscient(buffer, n);
		return (buffer);
	}
	buffer = ft_dtoa(i, tab[2][0] - 1 - n);
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = ft_addzero(buffer, tab[2][0]);
	return(buffer);
}

char		*get_shorter_up(va_list *arg, char *buffer, int **tab)
{
	int		n;

	n = 0;
	buffer = get_shorter(arg, buffer, tab);
	while(buffer[n])
	{
		buffer[n] = ft_toupper(buffer[n]);
		n++;
	}
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char		*get_binary(va_list *arg, char *buffer, int **tab)
{
	int		i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 2);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char		*get_percent(va_list *arg, char *buffer, int **tab)
{
	buffer = (char *) malloc(2 * sizeof(char));
	buffer[0] = '%';
	buffer[1] = '\0';
	return (buffer);
}
