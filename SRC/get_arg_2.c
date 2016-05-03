/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:35:36 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:08:02 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_hexa_low(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	char *(*modif_unsigned[7])(va_list *arg, char *buffer, int **tab, int base);

	init_unsigned_tab(modif_unsigned);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_unsigned[tab[3][0]](arg, buffer, tab, 16);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_hexa_up(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	int		i;
	char	*(*modif_unsigned[7])(va_list *arg, char *buf, int **tab, int base);

	init_unsigned_tab(modif_unsigned);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_unsigned[tab[3][0]](arg, buffer, tab, 16);
	i = 0;
	while (buffer[i])
	{
		buffer[i] = ft_toupper(buffer[i]);
		i++;
	}
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_double(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	double		i;
	long double	n;

	if (tab[2][0] == -1)
		tab[2][0] = 6;
	if (tab[3][0] == 7)
	{
		n = va_arg((*arg), long double);
		buffer = ft_dtoa(n, tab[2][0]);
	}
	else
	{
		i = va_arg((*arg), double);
		buffer = ft_dtoa(i, tab[2][0]);
	}
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_scient(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	double		i;
	long double	y;
	int			n;

	if (tab[2][0] == -1)
		tab[2][0] = 6;
	if (tab[3][0] == 7)
	{
		y = va_arg((*arg), long double);
		n = size_forscient_long(&y);
		buffer = ft_dtoa(y, tab[2][0]);
	}
	else
	{
		i = va_arg((*arg), double);
		n = size_forscient(&i);
		buffer = ft_dtoa(i, tab[2][0]);
	}
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = arg_forscient(buffer, n);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_scient_up(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	double		i;
	long double	y;
	int			n;

	n = 0;
	if (tab[2][0] == -1)
		tab[2][0] = 6;
	if (tab[3][0] == 7)
	{
		y = va_arg((*arg), long double);
		if (y)
			n = size_forscient_long(&y);
		buffer = ft_dtoa(y, tab[2][0]);
	}
	else
	{
		i = va_arg((*arg), double);
		if (i)
			n = size_forscient(&i);
		buffer = ft_dtoa(i, tab[2][0]);
	}
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = arg_forscient_up(buffer, n);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}
