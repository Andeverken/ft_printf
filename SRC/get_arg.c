/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:25:48 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/27 18:25:59 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_int(va_list *arg, char *buffer, int **tab)
{
	char	*(*modif_signed[7])(va_list *arg, char *buffer, int **tab);

	init_signed_tab(modif_signed);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_signed[tab[3][0]](arg, buffer, tab);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_char(va_list *arg, char *buffer, int **tab)
{
	char c;
	wchar_t i;

	if (tab[3][0] == 3)
		i = va_arg((*arg), wchar_t);
	else
	{
		c = va_arg((*arg), int);
		i = c;
	}
	elem->unicode = (wchar_t *) malloc(2 * sizeof(wchar_t));
	elem->unicode[0] = i;
	elem->unicode[1] = '\0';
	return (buffer);
}

char	*get_str(va_list *arg, char *buffer, int **tab)
{
	char *str;

	str = va_arg((*arg), char *);
	if(str)
	{
		buffer = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
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
	return (buffer);

}

char	*get_int_ns(va_list *arg, char *buffer, int **tab)
{
	unsigned int	i;
	char *(*modif_unsigned[7])(va_list *arg, char *buffer, int **tab, int base);

	init_unsigned_tab(modif_unsigned);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_unsigned[tab[3][0]](arg, buffer, tab, 10);
//	i = va_arg((*arg), unsigned int);
//	buffer = ft_itoa(i);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_octal(va_list *arg, char *buffer, int **tab)
{
	int i;
	char *(*modif_unsigned[7])(va_list *arg, char *buffer, int **tab, int base);

	init_unsigned_tab(modif_unsigned);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_unsigned[tab[3][0]](arg, buffer, tab, 8);
//	i = va_arg((*arg), int);
//	buffer = ft_convertbase(i, 8);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}
