/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:39:40 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:12:04 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"
#include <string.h>
#include <locale.h>
#include <limits.h>

void	ft_putunicode(t_list *elem, int **tab)
{
	int i;
	int n;

	i = 0;
	if (elem->aff_nul_uni && tab[1][0] > 0 && tab[0][0] == '-')
	{
		ft_memmove(elem->unicode + 1, elem->unicode, ft_wstrlen(elem->unicode));
		elem->unicode[0] = '\0';
	}
	while (elem->unicode[i] || elem->aff_nul_uni)
	{
		n = ft_size(elem->unicode[i]);
		if (elem->aff_nul_uni == 1 && !elem->unicode[i])
			elem->aff_nul_uni = 0;
		if (n <= 7)
			one_octet(elem, elem->unicode[i]);
		else if (n <= 11)
			two_octet(elem, elem->unicode[i]);
		else if (n <= 16)
			three_octet(elem, elem->unicode[i]);
		else
			four_octet(elem, elem->unicode[i]);
		i++;
	}
	ft_bzero(elem->unicode, i + 1);
}

int		ft_putprintf(t_list *elem, int **tab)
{
	int a;

	a = 0;
	if (elem->aff_nul && tab[1][0] > 0 && tab[0][0] == '-')
	{
		ft_memmove(elem->str + 1, elem->str, ft_strlen(elem->str));
		elem->str[0] = '\0';
	}
	while (elem->str[a] || elem->aff_nul)
	{
		if (!elem->str[a] && elem->aff_nul == 1)
		{
			write(1, &elem->str[a], 1);
			elem->aff_nul = 0;
		}
		else
			write(1, &elem->str[a], 1);
		a++;
	}
	elem->i = elem->i + a;
	ft_bzero(elem->str, a + 1);
	ft_putunicode(elem, tab);
	return (a);
}

/*char	*recup_arg(va_list *arg, t_list *elem, const char *format, int *i)
{
	if ((elem->str = print_arg(check_format(arg, format, i), arg, elem, format))
		== NULL)
		return (NULL);
	return (elem->str);
}*/

t_list	*create_struct(const char *format)
{
	t_list *elem;

	elem = (t_list *)malloc(sizeof(t_list));
	elem->str = (char *)malloc((ft_strlen(format) + 1) * sizeof(char));
	elem->unicode = (wchar_t *)malloc(sizeof(wchar_t));
	elem->unicode[0] = '\0';
	elem->i = 0;
	elem->aff_nul_uni = 0;
	elem->aff_nul = 0;
	ft_bzero(elem->str, ft_strlen(format) + 1);
	return (elem);
}

int		free_struct(t_list *elem)
{
	int i;

	ft_bzero(elem->unicode, ft_wstrlen(elem->unicode));
	free(elem->unicode);
	ft_putstr(elem->str);
	elem->i = elem->i + ft_strlen(elem->str);
	i = elem->i;
	ft_bzero(elem->str, ft_strlen(elem->str));
	free(elem->str);
	free(elem);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		n;
	va_list	arg;
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
			if ((elem->str = print_arg(check_format(&arg, format, &i), &arg,
							elem, format)) == NULL)
				return (-1);
			n = ft_strlen(elem->str);
		}
	}
	va_end(arg);
	i = free_struct(elem);
	return (i);
}

/*int		main(void)
{
	int i;
	char c;
	int n;

	i = 2000;
	setlocale(LC_ALL, "");
	c = 130;
	n = ft_printf("{%05.S}", L"42 c est cool");
	printf("%d\n", n);
	n = printf("{%05.S}", L"42 c est cool");
	printf("%d\n", n);
	return (0);
}*/
