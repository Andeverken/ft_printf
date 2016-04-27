/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_forscient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:32:10 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/27 17:35:00 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

int			size_forscient_long(long double *i)
{
	int		n;
	int		s;

	s = 1;
	n = 0;
	if ((*i) < 0)
	{
		s = -1;
		(*i) = -(*i);
	}
	if (((*i) > 9))
		while ((*i) > 9)
		{
			(*i) = (*i) / 10;
			n++;
		}
	else
		while (((*i) < 1))
		{
			(*i) *= 10;
			n--;
		}
	(*i) *= s;
	return(n);
}

int			size_forscient(double *i)
{
	int		n;
	int		s;

	s = 1;
	n = 0;
	if ((*i) < 0)
	{
		s = -1;
		(*i) = -(*i);
	}
	if (((*i) > 9))
		while ((*i) > 9)
		{
			(*i) = (*i) / 10;
			n++;
		}
	else
		while (((*i) < 1))
		{
			(*i) *= 10;
			n--;
		}
	(*i) *= s;
	return(n);
}

char		*arg_forscient_up(char *buffer, int n)
{
	int		i;
	char tmp[ft_strlen(buffer) + 5];

	ft_bzero(tmp, ft_strlen(buffer) + 5);
	ft_strcpy(tmp, buffer);
	i = ft_strlen(tmp);
	tmp[i++] = 'E';
	if (n < 0)
	{
		tmp[i++] = '-';
		n = -n;
	}
	else
		tmp[i++] = '+';
	if (n < 10)
		tmp[i++] = '0';
	ft_strcat(tmp, ft_itoa(n));
	free(buffer);
	buffer = malloc(ft_strlen(tmp) + 1);
	ft_bzero(buffer, ft_strlen(tmp) + 1);
	ft_strcpy(buffer, tmp);
	return (buffer);
}

char		*arg_forscient(char *buffer, int n)
{
	int		i;
	char tmp[ft_strlen(buffer) + 5];

	ft_bzero(tmp, ft_strlen(buffer) + 5);
	ft_strcpy(tmp, buffer);
	i = ft_strlen(tmp);
	tmp[i++] = 'e';
	if (n < 0)
	{
		tmp[i++] = '-';
		n = -n;
	}
	else
		tmp[i++] = '+';
	if (n < 10)
		tmp[i++] = '0';
	ft_strcat(tmp, ft_itoa(n));
	free(buffer);
	buffer = malloc(ft_strlen(tmp) + 1);
	ft_bzero(buffer, ft_strlen(tmp) + 1);
	ft_strcpy(buffer, tmp);
	return (buffer);
}
