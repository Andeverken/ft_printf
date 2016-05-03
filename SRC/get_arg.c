/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:25:48 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:13:28 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_int(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	char	*(*modif_signed[7])(va_list *arg, char *buffer, int **tab);

	init_signed_tab(modif_signed);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_signed[tab[3][0]](arg, buffer, tab);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_char(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	unsigned char	c;
	wchar_t			i;

	buffer = (char *)malloc(2 * sizeof(char));
	ft_bzero(buffer, 2);
	if (tab[3][0] == 3)
	{
		free(elem->unicode);
		elem->unicode = (wchar_t *)malloc(2 * sizeof(wchar_t));
		i = va_arg((*arg), wchar_t);
		elem->unicode[0] = i;
		elem->unicode[1] = '\0';
		if (i == '\0')
			elem->aff_nul_uni = 1;
	}
	else
	{
		c = va_arg((*arg), int);
		buffer[0] = c;
		if (c == '\0')
			elem->aff_nul = 1;
	}
	if ((elem->aff_nul_uni || elem->aff_nul) && tab[1][0] > 0)
		tab[1][0]--;
	return (buffer);
}

char	*get_str(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	char *str;

	if (tab[3][0] == 3)
		buffer = get_long_str(arg, buffer, tab, elem);
	else
	{
		str = va_arg((*arg), char *);
		if (str)
		{
			buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
			ft_bzero(buffer, ft_strlen(str) + 1);
			ft_strcpy(buffer, str);
		}
		else
		{
			buffer = (char *)malloc(7 * sizeof(char));
			ft_strcpy(buffer, "(null)\0");
		}
		if (tab[2][0] >= 0)
			buffer[tab[2][0]] = '\0';
	}
	return (buffer);
}

char	*get_int_ns(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	char *(*modif_unsigned[7])(va_list *arg, char *buffer, int **tab, int base);

	init_unsigned_tab(modif_unsigned);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_unsigned[tab[3][0]](arg, buffer, tab, 10);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_octal(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	char *(*modif_unsigned[7])(va_list *arg, char *buffer, int **tab, int base);

	init_unsigned_tab(modif_unsigned);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_unsigned[tab[3][0]](arg, buffer, tab, 8);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}
