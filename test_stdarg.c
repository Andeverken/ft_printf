/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:51:17 by rfernand          #+#    #+#             */
/*   Updated: 2016/03/22 16:09:15 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	test(char *format,...)
{
	va_list ap;
	char c;
	char *str;
	int i;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*++format)
			{
				case 'c' :
					c = va_arg(ap, int);
					printf("%c", c);
					break;
				case 's' :
					str = va_arg(ap, char *);
					printf("%s", str);
					break;
				case 'i' :
					i = va_arg(ap, int);
					printf("%d", i);
					break;
			}
		}
		else
			format++;
	}
	va_end(ap);
}

int		main(void)
{
	test("%s", "Salut");
	return (0);
}
