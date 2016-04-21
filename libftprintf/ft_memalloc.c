/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:23:57 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/18 19:14:51 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *pts;

	pts = (void*)malloc(size);
	if (!pts)
		return (NULL);
	ft_bzero(pts, size);
	return (pts);
}
