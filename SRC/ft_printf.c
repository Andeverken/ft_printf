/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:39:40 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/22 18:35:37 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"
#include <string.h>

int		ft_putprintf(char *line)
{
	int a;

	a = 0;
	while (line[a])
	{
		if (line[a] == -127)
			line[a] = 0;
		write(1, &line[a], 1);
		a++;
	}
	return(a);
}

char	*recup_arg(va_list *arg, char *str, const char *format, int *i)
{
/*	int y;

	y = 0;
	while (format[(*i) - y - 1] == '\\')
		y++;
	if (y % 2)
		str[(*i)] = '\0';
*/	if ((str = print_arg(check_format(arg, format, i), arg, str, format))
		== NULL)
		return (NULL);
	return (str);
}

int		ft_printf(const char * format, ...)
{
	int i;
	int n;
	char *str;
	va_list arg;

	i = 0;
	n = 0;
	va_start(arg, format);
	str = (char *) malloc((ft_strlen(format) + 1) * sizeof(char));
	ft_bzero(str, ft_strlen(format) + 1);
	while (format[i])
	{
		if (format[i] != '%')
			str[n++] = format[i++];
		else
		{
			if ((str = recup_arg(&arg, str, format, &i)) == NULL)
					return (-1);
			n = ft_strlen(str);
		}
	}
	va_end(arg);
	i = ft_putprintf(str);
	free(str);
	return (i);
}

int		main(void)
{
	double i;
	char c;
	int n;

	c = 130;
	i = 1000000.7776678;
	n = ft_printf("% s", "test");
	printf("%d\n", n);
	n = printf("% s", "test");
	printf("%d\n", n);
	return (0);
}
