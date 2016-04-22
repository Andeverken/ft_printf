/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nothing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 17:21:10 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/22 18:33:41 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_nothing(va_list *arg, char *buffer, int **tab)
{
	buffer = (char *)malloc (2 * sizeof(char));
	buffer[0] = tab[4][1];
	buffer[1] = '\0';
	return (buffer);
}

char	*get_long_str(va_list *arg, char *buffer, int **tab)
{
	wchar_t *tmp;
	int i;

	i = 0;
	tmp = va_arg((*arg), wchar_t*);
	while (tmp[i])
	{
		write(1, &tmp[i], 1);
		i++;
	}
	return (buffer);
}
