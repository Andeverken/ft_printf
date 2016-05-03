/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag_uni.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:47:12 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:17:40 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*ft_apply_flag_uni(int **tab, t_list *elem, char *buffer)
{
	int		i;
	int		n;
	char	*tmp;

	i = 0;
	n = 0;
	tmp = (char *)malloc(1 * sizeof(char));
	tmp[0] = '\0';
	free(buffer);
	while (elem->unicode[i])
	{
		n += ft_size_octet(elem->unicode[i]);
		i++;
	}
	if (n < tab[1][0])
	{
		free(tmp);
		i = 0;
		tmp = (char *)malloc((tab[1][0] - n + 1) * sizeof(char));
		ft_bzero(tmp, tab[1][0] - n + 1);
		while (tab[1][0] > n++)
			tmp[i++] = tab[0][3];
	}
	return (tmp);
}
