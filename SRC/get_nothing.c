/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nothing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 17:21:10 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:06:38 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_nothing(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	buffer = (char *)malloc(2 * sizeof(char));
	buffer[0] = tab[4][1];
	buffer[1] = '\0';
	return (buffer);
}

int		ft_wstrlen(wchar_t *unicode)
{
	int i;

	i = 0;
	while (unicode[i])
		i++;
	return (i);
}

void	ft_wcharcpy(wchar_t *dst, wchar_t *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*get_long_str(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	wchar_t *tmp;

	buffer = (char *)malloc(sizeof(char));
	ft_bzero(buffer, 2);
	free(elem->unicode);
	tmp = va_arg((*arg), wchar_t*);
	if (tmp)
	{
		elem->unicode = (wchar_t *)malloc((ft_wstrlen(tmp) + 1) *
				sizeof(wchar_t));
		ft_bzero(elem->unicode, ft_wstrlen(tmp));
		ft_wcharcpy(elem->unicode, tmp);
	}
	else
	{
		elem->unicode = (wchar_t*)malloc(7 * sizeof(wchar_t));
		ft_wcharcpy(elem->unicode, L"(null)");
	}
	if (tab[2][0] >= 0)
		apply_accuracy_wchar(elem, tab);
	return (buffer);
}
