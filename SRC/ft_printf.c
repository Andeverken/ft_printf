/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:39:40 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/04 16:46:55 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*recup_arg(va_list *arg, char *str, const char *format, int *i)
{
	int y;

	y = 0;
	while (format[(*i) - y - 1] == '\\')
		y++;
	if (y % 2)
		str[(*i)] = '\0';
	if ((str = print_arg(check_format(format, i), arg, str, format)) == NULL)
		return (NULL);
	return (str);
}

int		ft_printf(const char * format, ...)
{
	int i;
	int n;
	int y;
	char *str;
	va_list arg;

	i = 0;
	n = 0;
	va_start(arg, format);
	str = (char *) malloc((ft_strlen(format) + 1) * sizeof(char));
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
	ft_putstr(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int		main(void)
{
	ft_printf("string = %s%X\n", "Salut", 15);
	return (0);
}
