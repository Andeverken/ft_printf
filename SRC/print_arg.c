/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:55:42 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/12 17:43:09 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*print_arg(int **tab, va_list *arg, char *str, const char *format)
{
	char *buffer;
	char *buf;
	int n;
	char	*(*types[14])(va_list *arg, char *buffer, int *tab);

	n = ft_strlen(str);
	buffer = NULL;
	buf = (char *)malloc((n + 1) * sizeof(char));
	ft_strcpy(buf, str);
	if (!tab[4][0])
		return (NULL);
	init_pt_tab(types);
	buffer = types[tab[4][0]](arg, buffer, tab[3]);
	free (str);
	str = (char *) malloc((n + ft_strlen(buffer) + ft_strlen(format) + 1) *
			sizeof (char));
	ft_bzero(str, n + ft_strlen(buffer) + ft_strlen(format) + 1);
	ft_strcpy(str, buf);
	free(buf);
	ft_strcat(str, buffer);
	free(buffer);
	return (str);
}
