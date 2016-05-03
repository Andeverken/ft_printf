/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:11:35 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:04:37 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

int			ft_size(wchar_t value)
{
	char	*tmp;
	int		i;

	tmp = ft_convertbase(value, 2);
	i = ft_strlen(tmp);
	free(tmp);
	return (i);
}

void		one_octet(t_list *elem, wchar_t unicode)
{
	write(1, &unicode, 1);
	(elem->i)++;
}

void		two_octet(t_list *elem, wchar_t unicode)
{
	unsigned int	mask;
	unsigned char	o1;
	unsigned char	o2;
	unsigned int	v;
	unsigned char	octet;

	mask = 49280;
	v = unicode;
	o2 = (v << 26) >> 26;
	o1 = ((v >> 6) << 27) >> 27;
	octet = (mask >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o2;
	write(1, &octet, 1);
	elem->i = elem->i + 2;
}

void		three_octet(t_list *elem, wchar_t unicode)
{
	unsigned int	mask;
	unsigned char	o1;
	unsigned char	o2;
	unsigned int	v;
	unsigned char	octet;

	mask = 14712960;
	v = unicode;
	elem->o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	octet = (mask >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | elem->o3;
	write(1, &octet, 1);
	elem->i = elem->i + 3;
}

void		four_octet(t_list *elem, wchar_t unicode)
{
	unsigned int	mask;
	unsigned char	o1;
	unsigned char	o2;
	unsigned int	v;
	unsigned char	octet;

	mask = 4034953344;
	v = unicode;
	elem->o4 = (v << 26) >> 26;
	elem->o3 = ((v >> 6) << 26) >> 26;
	o2 = ((v >> 12) << 26) >> 26;
	o1 = ((v >> 18) << 29) >> 29;
	octet = (mask >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask << 8) >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o1;
	write(1, &octet, 1);
	elem->i = elem->i + 4;
}
