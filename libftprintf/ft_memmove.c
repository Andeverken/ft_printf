/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:42:42 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/18 19:13:10 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*buf;

	if (!(buf = ft_memalloc(len)))
		return (dst);
	buf = ft_memcpy(buf, src, len);
	dst = ft_memcpy(dst, buf, len);
	free(buf);
	return (dst);
}
