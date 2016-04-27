/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:39:40 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/27 18:19:39 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"
#include <string.h>

void	ft_putunicode(t_list *elem, int **tab)
{
	int i;

	i = 0;
	if (!elem->unicode[0] && tab[4][0] == 13)
	{
		write(1, &elem->unicode[0], 1);
		elem->i++;
	}
	while (elem->unicode[i])
	{
		if (elem->unicode[i] <= 0x7F)
			write(1, &elem->unicode[i], 1);
		else if (elem->unicode[i] <= 0x7FF)
			write(1, &elem->unicode[i], 2);
		else if (elem->unicode[i] <= 0xFFFF)
			write(1, &elem->unicode[i], 3);
		else if (elem->unicode[i] <= 0x1FFFF)
			write(1, &elem->unicode[i], 4);
		i++;
	}
	elem->i = elem->i + i;
	if (elem->unicode)
		free(elem->unicode);
}

int		ft_putprintf(t_list *elem, int **tab)
{
	int a;

	a = 0;
	while (elem->str[a])
	{
		if (elem->str[a] == -127)
			elem->str[a] = 0;
		write(1, &elem->str[a], 1);
		a++;
	}
	elem->i = elem->i + a;
	ft_bzero(elem->str, a);
	ft_putunicode(elem, tab);
	return(a);
}

char	*recup_arg(va_list *arg, t_list *elem, const char *format, int *i)
{
	if ((elem->str = print_arg(check_format(arg, format, i), arg, elem, format))
		== NULL)
		return (NULL);
	return (elem->str);
}

t_list	*create_struct(const char *format)
{
	t_list *elem;

	elem = (t_list *) malloc(sizeof(t_list));
	elem->str = (char *) malloc((ft_strlen(format) + 1) * sizeof(char));
	ft_bzero(elem->str, ft_strlen(format) + 1);
	return (elem);
}

int		ft_printf(const char * format, ...)
{
	int i;
	int n;
	va_list arg;
	t_list	*elem;

	i = 0;
	n = 0;
	va_start(arg, format);
	elem = create_struct(format);
	ft_bzero(elem->str, ft_strlen(format) + 1);
	while (format[i])
	{
		if (format[i] != '%')
			elem->str[n++] = format[i++];
		else
		{
			if ((elem->str = recup_arg(&arg, elem, format, &i)) == NULL)
					return (-1);
			n = ft_strlen(elem->str);
		}
	}
	va_end(arg);
	return (elem->i);
}

/*int		main(void)
{
	double i;
	char c;
	int n;

	c = 130;
	i = 1000000.7776678;
	n = ft_printf("%Le", (long double) -1);
	printf("%d\n", n);
	n = printf("%Le", (long double) -1);
	printf("%d\n", n);
	return (0);
}*/
