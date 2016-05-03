/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_accuracy_wchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:21:46 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/29 13:34:18 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

int		ft_size_octet(wchar_t unicode)
{
	int i;

	i = ft_size(unicode);
	if (i <= 7)
		return (1);
	else if (i <= 11)
		return (2);
	else if (i <= 16)
		return (3);
	else
		return (4);
}

void	apply_accuracy_wchar(t_list *elem, int **tab)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (n <= tab[2][0] && elem->unicode[i])
	{
		n = n + ft_size_octet(elem->unicode[i]);
		if (n > tab[2][0])
			elem->unicode[i] = '\0';
		i++;
	}
}
