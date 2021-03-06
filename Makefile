SRC/                                                                                                000755  034027  010202  00000000000 13046061313 013123  5                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         SRC/apply_accuracy_wchar.c                                                                          000644  034027  010202  00000002514 13046061313 017454  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_accuracy_wchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:21:46 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/29 13:34:18 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

int		ft_size_octet(wchar_t unicode)
{
	int i;

	i = ft_size(unicode);
	if (i <= 7)
		return (1);
	else if (i <= 11)
		return (2);
	else if (i <= 16)
		return (3);
	else
		return (4);
}

void	apply_accuracy_wchar(t_list *elem, int **tab)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (n <= tab[2][0] && elem->unicode[i])
	{
		n = n + ft_size_octet(elem->unicode[i]);
		if (n > tab[2][0])
			elem->unicode[i] = '\0';
		i++;
	}
}
                                                                                                                                                                                    SRC/apply_diez.c                                                                                    000644  034027  010202  00000004525 13046061313 015435  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diez.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:30:16 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:23:53 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*apply_diez_octal(char *tmp, char *buffer, int **tab)
{
	if (buffer[0] == '0')
		return (buffer);
	tmp[0] = '0';
	return (buffer);
}

char		*apply_diez_hexa_low(char *tmp, char *buffer, int **tab)
{
	int i;

	i = 0;
	while (buffer[i] == '0')
		i++;
	if (i != 1 && buffer[i] != '\0' && tab[2][0] != 0)
	{
		tmp[0] = '0';
		tmp[1] = 'x';
	}
	return (buffer);
}

char		*apply_diez_hexa_up(char *tmp, char *buffer, int **tab)
{
	int i;

	i = 0;
	while (buffer[i] == '0')
		i++;
	if (i != 1 && buffer[i] != '\0' && tab[2][0] != 0)
	{
		tmp[0] = '0';
		tmp[1] = 'X';
	}
	return (buffer);
}

char		*apply_diez_double(char *tmp, char *buffer, int **tab)
{
	char	str[ft_strlen(buffer) + 2];

	if (ft_strchr(buffer, '.'))
		return (buffer);
	ft_bzero(str, ft_strlen(buffer) + 2);
	ft_strcpy(str, buffer);
	str[ft_strlen(str)] = '.';
	free(buffer);
	buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_bzero(buffer, ft_strlen(str) + 1);
	ft_strcpy(buffer, str);
	return (buffer);
}

char		*apply_diez_scient_low(char *tmp, char *buffer, int **tab)
{
	char	str[ft_strlen(buffer) + 2];

	if (ft_strchr(buffer, '.'))
		return (buffer);
	ft_bzero(str, ft_strlen(buffer) + 2);
	str[0] = buffer[0];
	str[1] = '.';
	ft_memmove(buffer, buffer + 1, ft_strlen(buffer));
	ft_strcat(str, buffer);
	free(buffer);
	buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_bzero(buffer, ft_strlen(str) + 1);
	ft_strcpy(buffer, str);
	return (buffer);
}
                                                                                                                                                                           SRC/arg_forscient.c                                                                                 000644  034027  010202  00000004553 13046061313 016123  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_forscient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:32:10 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:22:28 by rfernand         ###   ########.fr       */
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
	return (n);
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
	return (n);
}

char		*arg_forscient_up(char *buffer, int n)
{
	int		i;
	char	tmp[ft_strlen(buffer) + 5];

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
	char	tmp[ft_strlen(buffer) + 5];

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
                                                                                                                                                     SRC/check_accuracy.c                                                                                000644  034027  010202  00000003155 13046061313 016222  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accuracy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:31:16 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:32:12 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

static void	get_accurary(int **tab, const char *format, int *i)
{
	int		n;
	char	str[50];

	n = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
		str[n++] = format[(*i)++];
	str[n] = 'e';
	tab[2][0] = ft_atoi(str);
}

int			check_accuracy(va_list *arg, int **tab, const char *format, int *i)
{
	char	str[50];
	int		n;

	n = 0;
	if (format[*i] == '.')
	{
		(*i)++;
		if ((format[*i] < '0' || format[*i] > '9') && format[*i] != '*')
			tab[2][0] = 0;
		else if (format[*i] == '*')
		{
			tab[2][0] = va_arg((*arg), int);
			if (tab[2][0] < 0)
				tab[2][0] = -1;
			(*i)++;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
			get_accurary(tab, format, i);
		return (1);
	}
	tab[2][0] = -1;
	return (0);
}
                                                                                                                                                                                                                                                                                                                                                                                                                   SRC/check_flags.c                                                                                   000644  034027  010202  00000002633 13046061313 015524  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:45:34 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:32:41 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_flags(int *tab, const char *format, int *i)
{
	while (format[*i] == '-' || format[*i] == '+' || format[*i] == ' ' ||
			format[*i] == '#' || format[*i] == '0')
	{
		if (format[*i] == '-' && tab[0] != '-')
			tab[0] = '-';
		if (format[*i] == '+' && tab[1] != '+')
			tab[1] = '+';
		if (format[*i] == ' ' && tab[1] != ' ' && tab[1] != '+')
			tab[1] = ' ';
		if (format[*i] == '#' && tab[2] != '#')
			tab[2] = '#';
		if (format[*i] == '0' && tab[0] != '0' && tab[0] != '-')
		{
			tab[0] = '0';
			tab[3] = '0';
		}
		(*i)++;
	}
}
                                                                                                     SRC/check_format.c                                                                                  000644  034027  010202  00000004654 13046061313 015725  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:32:30 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:16:48 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

int		*alloc_tab(int n)
{
	int *tab;
	int i;

	i = 0;
	tab = (int *)malloc(n * sizeof(int));
	while (i < n)
		tab[i++] = 0;
	return (tab);
}

void	init_tab(int **tab)
{
	tab[0] = alloc_tab(4);
	tab[1] = alloc_tab(1);
	tab[2] = alloc_tab(1);
	tab[3] = alloc_tab(1);
	tab[4] = alloc_tab(2);
}

int		check(char c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == ' ' || c == '#'
			|| c == '.' || c == '*' || c == 'l' || c == 'z' || c == 'L' ||
			(c >= 'b' && c <= 'j') || c == 's' || c == 'o' || c == 'u' ||
			c == 'S' || c == 'O' || c == 'U' || (c >= 'B' && c <= 'G') ||
			c == 'p' || c == '%' || c == 'I' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		is_modif(char c)
{
	if (c == 'h' || c == 'j' || c == 'l' || c == 'z' || c == 'L')
		return (1);
	return (0);
}

int		**check_format(va_list *arg, const char *format, int *i)
{
	int **tab;
	int n;

	*i = *i + 1;
	n = 0;
	tab = (int **)malloc(5 * sizeof(int *));
	init_tab(tab);
	while (!tab[4][0] && format[*i] && check(format[*i]))
	{
		check_flags(tab[0], format, i);
		check_len(arg, tab, format, i);
		if (!n || format[*i] == '.')
			n = check_accuracy(arg, tab, format, i);
		if (is_modif(format[*i]))
			check_modif(tab[3], format, i);
		if (check_type(tab, format[*i]))
			*i = *i + 1;
	}
	if (tab[0][0] != '0' || (tab[2][0] < tab[1][0] && tab[2][0] != -1 &&
				tab[4][0] != 11 && tab[4][0] != 12 && tab[4][0] != 15 &&
				tab[4][0] != 0 && tab[4][0] != 16))
		tab[0][3] = ' ';
	if (!tab[4][0] && format[*i])
		tab[4][1] = format[(*i)++];
	return (tab);
}
                                                                                    SRC/check_len.c                                                                                     000644  034027  010202  00000003107 13046061313 015203  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:03:27 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:21:51 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

static void		star_len(int **tab)
{
	if (tab[1][0] < 0)
	{
		tab[0][0] = '-';
		tab[1][0] = -tab[1][0];
	}
}

void			check_len(va_list *arg, int **tab, const char *format, int *i)
{
	char	str[200];
	int		n;

	n = 0;
	if (format[*i] != '0' && format[*i] != '*')
	{
		while (format[*i] >= '0' && format[*i] <= '9')
			str[n++] = format[(*i)++];
		str[n] = 'e';
		if (ft_atoi(str) || !tab[1][0])
			tab[1][0] = ft_atoi(str);
	}
	else if (format[*i] == '0' && !tab[0])
	{
		(*i)++;
		while (format[*i] >= '0' && format[*i] <= '9')
			str[n++] = format[(*i)++];
		str[n] = 'e';
	}
	else if (format[*i] == '*')
	{
		tab[1][0] = va_arg((*arg), int);
		star_len(tab);
		(*i)++;
	}
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                         SRC/check_modif.c                                                                                   000644  034027  010202  00000002646 13046061313 015532  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:55:18 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/16 14:58:34 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_modif(int *tab, const char *format, int *i)
{
	if (format[(*i)] == 'h' && tab[0] < 3)
	{
		if (format[(*i) + 1] == 'h' && tab[0] < 2)
			tab[0] = 1;
		else
			tab[0] = 2;
	}
	else if (format[(*i)] == 'l')
	{
		if (format[(*i) + 1] == 'l')
			tab[0] = 4;
		else if (tab[0] < 4)
			tab[0] = 3;
	}
	else if (format[(*i)] == 'j' && tab[0] != 4 && tab[0] != 6)
		tab[0] = 5;
	else if (format[(*i)] == 'z' && tab[0] != 4)
		tab[0] = 6;
	else if (format[(*i)] == 'L')
		tab[0] = 7;
	if (tab[0])
		(*i)++;
	if (tab[0] == 1 || tab[0] == 4)
		(*i)++;
}
                                                                                          SRC/check_type.c                                                                                    000644  034027  010202  00000003614 13046061313 015411  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:32:59 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/29 12:30:29 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

void	check_type_3(int **tab, char c)
{
	if (c == 'X')
		tab[4][0] = 5;
	if (c == 'f' || c == 'F')
		tab[4][0] = 6;
	if (c == 'e')
		tab[4][0] = 7;
	if (c == 'E')
		tab[4][0] = 8;
}

void	check_type_2(int **tab, char c)
{
	if (c == 'g')
		tab[4][0] = 9;
	if (c == 'G')
		tab[4][0] = 10;
	if (c == 'c' || c == 'C')
	{
		tab[4][0] = 11;
		if (c == 'C')
			tab[3][0] = 3;
	}
	if (c == 's')
		tab[4][0] = 12;
	if (c == 'p')
		tab[4][0] = 13;
	if (c == 'b' || c == 'B')
		tab[4][0] = 14;
	if (c == '%')
		tab[4][0] = 15;
	if (c == 'x')
		tab[4][0] = 4;
	check_type_3(tab, c);
}

int		check_type(int **tab, char c)
{
	if (c == 'd' || c == 'i' || c == 'D' || c == 'I')
	{
		tab[4][0] = 1;
		if (c == 'D' || c == 'I')
			tab[3][0] = 3;
	}
	if (c == 'o' || c == 'O')
	{
		tab[4][0] = 2;
		if (c == 'O')
			tab[3][0] = 3;
	}
	if (c == 'u' || c == 'U')
	{
		tab[4][0] = 3;
		if (c == 'U')
			tab[3][0] = 3;
	}
	if (c == 'S')
		tab[4][0] = 16;
	check_type_2(tab, c);
	if (tab[4][0])
		return (1);
	return (0);
}
                                                                                                                    SRC/fill_point.c                                                                                    000644  034027  010202  00000002637 13046061313 015436  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:32:00 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:19:05 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*fill_point(char *buffer, int **tab)
{
	char	tmp[15];
	int		i;
	int		n;

	n = 3;
	ft_bzero(tmp, 15);
	i = ft_strlen(buffer);
	tmp[0] = '0';
	tmp[1] = 'x';
	if (buffer[0] != '0' || tab[2][0] >= 1)
		ft_strcat(tmp, buffer);
	free(buffer);
	buffer = (char *)malloc(15 * sizeof(char));
	ft_bzero(buffer, 15);
	ft_strcpy(buffer, tmp);
	return (buffer);
}

void		ft_delete_zero(char *str)
{
	int a;

	a = ft_strlen(str) - 1;
	while (str[a] == '0')
		str[a--] = '\0';
	if (str[a] == '.')
		str[a] = '\0';
}
                                                                                                 SRC/ft_addzero.c                                                                                    000644  034027  010202  00000002636 13046061313 015417  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 14:53:50 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:18:05 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*ft_addzero(char *str, int size)
{
	int		i;
	int		n;
	char	buf[size + 1];

	ft_bzero(buf, size + 1);
	n = 0;
	if (str[0] == '0' && size == 0)
		str[0] = '\0';
	else if ((i = ft_strlen(str)) <= size)
	{
		if (str[0] == '-')
		{
			buf[n++] = '-';
			ft_memmove(str, str + 1, ft_strlen(str));
			i--;
		}
		while (i++ < size)
			buf[n++] = '0';
		ft_strcat(buf, str);
		free(str);
		str = (char*)malloc((size + 2) * sizeof(char));
		ft_bzero(str, size + 1);
		ft_strcpy(str, buf);
	}
	return (str);
}
                                                                                                  SRC/ft_apply_flag_uni.c                                                                             000644  034027  010202  00000002601 13046061313 016750  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
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
                                                                                                                               SRC/ft_printf.c                                                                                     000644  034027  010202  00000006270 13046061313 015267  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:39:40 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/16 14:58:26 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

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
                                                                                                                                                                                                                                                                                                                                        SRC/ft_round.c                                                                                      000644  034027  010202  00000003124 13046061313 015107  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:56:49 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:15:25 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

static char		*ft_resize_round(char *str)
{
	char buffer[ft_strlen(str) + 2];

	ft_bzero(buffer, ft_strlen(str) + 2);
	buffer[0] = '1';
	ft_strcat(buffer, str);
	free(str);
	str = (char*)malloc((ft_strlen(buffer) + 1) * sizeof(char));
	ft_strcpy(str, buffer);
	return (str);
}

char			*ft_round(char *str, int size)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] <= '5')
		str[i] = '\0';
	else
	{
		size--;
		if (str[size] == '.')
			size--;
		if (str[size] == '9')
		{
			ft_round(str, size);
			str[size] = '0';
		}
		else if (size >= 0)
			str[size] = str[size] + 1;
		str[i] = '\0';
	}
	if (str[0] == '0' && size == ft_strlen(str) - 1)
		str = ft_resize_round(str);
	return (str);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                            SRC/get_arg.c                                                                                       000644  034027  010202  00000005756 13046061313 014714  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:25:48 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:13:28 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_int(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	char	*(*modif_signed[7])(va_list *arg, char *buffer, int **tab);

	init_signed_tab(modif_signed);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_signed[tab[3][0]](arg, buffer, tab);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_char(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	unsigned char	c;
	wchar_t			i;

	buffer = (char *)malloc(2 * sizeof(char));
	ft_bzero(buffer, 2);
	if (tab[3][0] == 3)
	{
		free(elem->unicode);
		elem->unicode = (wchar_t *)malloc(2 * sizeof(wchar_t));
		i = va_arg((*arg), wchar_t);
		elem->unicode[0] = i;
		elem->unicode[1] = '\0';
		if (i == '\0')
			elem->aff_nul_uni = 1;
	}
	else
	{
		c = va_arg((*arg), int);
		buffer[0] = c;
		if (c == '\0')
			elem->aff_nul = 1;
	}
	if ((elem->aff_nul_uni || elem->aff_nul) && tab[1][0] > 0)
		tab[1][0]--;
	return (buffer);
}

char	*get_str(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	char *str;

	if (tab[3][0] == 3)
		buffer = get_long_str(arg, buffer, tab, elem);
	else
	{
		str = va_arg((*arg), char *);
		if (str)
		{
			buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
			ft_bzero(buffer, ft_strlen(str) + 1);
			ft_strcpy(buffer, str);
		}
		else
		{
			buffer = (char *)malloc(7 * sizeof(char));
			ft_strcpy(buffer, "(null)\0");
		}
		if (tab[2][0] >= 0)
			buffer[tab[2][0]] = '\0';
	}
	return (buffer);
}

char	*get_int_ns(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	char *(*modif_unsigned[7])(va_list *arg, char *buffer, int **tab, int base);

	init_unsigned_tab(modif_unsigned);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_unsigned[tab[3][0]](arg, buffer, tab, 10);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_octal(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	char *(*modif_unsigned[7])(va_list *arg, char *buffer, int **tab, int base);

	init_unsigned_tab(modif_unsigned);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_unsigned[tab[3][0]](arg, buffer, tab, 8);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}
                  SRC/get_arg_2.c                                                                                     000644  034027  010202  00000006233 13046061313 015124  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:35:36 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:08:02 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_hexa_low(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	char *(*modif_unsigned[7])(va_list *arg, char *buffer, int **tab, int base);

	init_unsigned_tab(modif_unsigned);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_unsigned[tab[3][0]](arg, buffer, tab, 16);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_hexa_up(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	int		i;
	char	*(*modif_unsigned[7])(va_list *arg, char *buf, int **tab, int base);

	init_unsigned_tab(modif_unsigned);
	if (tab[2][0] == -1)
		tab[2][0] = 1;
	buffer = modif_unsigned[tab[3][0]](arg, buffer, tab, 16);
	i = 0;
	while (buffer[i])
	{
		buffer[i] = ft_toupper(buffer[i]);
		i++;
	}
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_double(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	double		i;
	long double	n;

	if (tab[2][0] == -1)
		tab[2][0] = 6;
	if (tab[3][0] == 7)
	{
		n = va_arg((*arg), long double);
		buffer = ft_dtoa(n, tab[2][0]);
	}
	else
	{
		i = va_arg((*arg), double);
		buffer = ft_dtoa(i, tab[2][0]);
	}
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_scient(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	double		i;
	long double	y;
	int			n;

	if (tab[2][0] == -1)
		tab[2][0] = 6;
	if (tab[3][0] == 7)
	{
		y = va_arg((*arg), long double);
		n = size_forscient_long(&y);
		buffer = ft_dtoa(y, tab[2][0]);
	}
	else
	{
		i = va_arg((*arg), double);
		n = size_forscient(&i);
		buffer = ft_dtoa(i, tab[2][0]);
	}
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = arg_forscient(buffer, n);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char	*get_scient_up(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	double		i;
	long double	y;
	int			n;

	n = 0;
	if (tab[2][0] == -1)
		tab[2][0] = 6;
	if (tab[3][0] == 7)
	{
		y = va_arg((*arg), long double);
		if (y)
			n = size_forscient_long(&y);
		buffer = ft_dtoa(y, tab[2][0]);
	}
	else
	{
		i = va_arg((*arg), double);
		if (i)
			n = size_forscient(&i);
		buffer = ft_dtoa(i, tab[2][0]);
	}
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = arg_forscient_up(buffer, n);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}
                                                                                                                                                                                                                                                                                                                                                                     SRC/get_arg_3.c                                                                                     000644  034027  010202  00000004662 13046061313 015131  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:31:41 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:14:08 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*get_point(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	long		i;

	if (tab[2][0] == -1)
		tab[2][0] = 1;
	i = va_arg((*arg), long);
	buffer = ft_convertbase(i, 16);
	buffer = ft_addzero(buffer, tab[2][0]);
	buffer = fill_point(buffer, tab);
	return (buffer);
}

char		*get_shorter(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	double	i;
	int		n;
	double	y;
	int		a;

	if (tab[2][0] == -1)
		tab[2][0] = 6;
	n = 0;
	i = va_arg((*arg), double);
	y = i;
	if (y)
		n = size_forscient(&y);
	if (n > tab[2][0] - 1)
	{
		buffer = ft_dtoa(y, tab[2][0] - 1);
		if (ft_strlen(buffer) > 2)
			buffer = ft_round(buffer, ft_strlen(buffer) - 1);
		ft_delete_zero(buffer);
		buffer = arg_forscient(buffer, n);
		return (buffer);
	}
	buffer = ft_dtoa(i, tab[2][0] - 1 - n);
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char		*get_shorter_up(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	int		n;

	n = 0;
	buffer = get_shorter(arg, buffer, tab, elem);
	while (buffer[n])
	{
		buffer[n] = ft_toupper(buffer[n]);
		n++;
	}
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char		*get_binary(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	int		i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 2);
	buffer = ft_addzero(buffer, tab[2][0]);
	return (buffer);
}

char		*get_percent(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	buffer = (char *)malloc(2 * sizeof(char));
	buffer[0] = '%';
	buffer[1] = '\0';
	return (buffer);
}
                                                                              SRC/get_int.c                                                                                       000644  034027  010202  00000003175 13046061313 014726  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:31:27 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/20 18:42:55 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_normal_int(va_list *arg, char *buffer, int **tab)
{
	int i;

	i = va_arg((*arg), int);
	buffer = ft_itoa(i);
	return (buffer);
}

char	*get_short_short_int(va_list *arg, char *buffer, int **tab)
{
	signed char i;

	i = va_arg((*arg), int);
	buffer = ft_itoa(i);
	return (buffer);
}

char	*get_short_int(va_list *arg, char *buffer, int **tab)
{
	short i;

	i = va_arg((*arg), int);
	buffer = ft_itoa(i);
	return (buffer);
}

char	*get_long_int(va_list *arg, char *buffer, int **tab)
{
	long i;

	i = va_arg((*arg), long);
	buffer = ft_itoa(i);
	return (buffer);
}

char	*get_long_long_int(va_list *arg, char *buffer, int **tab)
{
	long long i;

	i = va_arg((*arg), long long);
	buffer = ft_itoa(i);
	return (buffer);
}
                                                                                                                                                                                                                                                                                                                                                                                                   SRC/get_int_2.c                                                                                     000644  034027  010202  00000002307 13046061313 015143  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:38:52 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/20 18:39:50 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_int_max(va_list *arg, char *buffer, int **tab)
{
	intmax_t i;

	i = va_arg((*arg), intmax_t);
	buffer = ft_itoa(i);
	return (buffer);
}

char	*get_size_int(va_list *arg, char *buffer, int **tab)
{
	size_t i;

	i = va_arg((*arg), size_t);
	buffer = ft_itoa(i);
	return (buffer);
}
                                                                                                                                                                                                                                                                                                                         SRC/get_nothing.c                                                                                   000644  034027  010202  00000003567 13046061313 015607  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nothing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 17:21:10 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:06:38 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_nothing(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	buffer = (char *)malloc(2 * sizeof(char));
	buffer[0] = tab[4][1];
	buffer[1] = '\0';
	return (buffer);
}

int		ft_wstrlen(wchar_t *unicode)
{
	int i;

	i = 0;
	while (unicode[i])
		i++;
	return (i);
}

void	ft_wcharcpy(wchar_t *dst, wchar_t *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*get_long_str(va_list *arg, char *buffer, int **tab, t_list *elem)
{
	wchar_t *tmp;

	buffer = (char *)malloc(sizeof(char));
	ft_bzero(buffer, 2);
	free(elem->unicode);
	tmp = va_arg((*arg), wchar_t*);
	if (tmp)
	{
		elem->unicode = (wchar_t *)malloc((ft_wstrlen(tmp) + 1) *
				sizeof(wchar_t));
		ft_bzero(elem->unicode, ft_wstrlen(tmp));
		ft_wcharcpy(elem->unicode, tmp);
	}
	else
	{
		elem->unicode = (wchar_t*)malloc(7 * sizeof(wchar_t));
		ft_wcharcpy(elem->unicode, L"(null)");
	}
	if (tab[2][0] >= 0)
		apply_accuracy_wchar(elem, tab);
	return (buffer);
}
                                                                                                                                         SRC/get_unsigned.c                                                                                  000644  034027  010202  00000003562 13046061313 015750  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:03:18 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/26 17:52:29 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_normal_unsigned(va_list *arg, char *buffer, int **tab, int base)
{
	unsigned int i;

	i = va_arg((*arg), unsigned int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_short_short_unsigned(va_list *arg, char *buffer, int **tab,
		int base)
{
	unsigned char i;

	i = va_arg((*arg), unsigned int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_short_unsigned(va_list *arg, char *buffer, int **tab, int base)
{
	unsigned short int i;

	i = va_arg((*arg), unsigned int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_long_unsigned(va_list *arg, char *buffer, int **tab, int base)
{
	unsigned long int i;

	i = va_arg((*arg), unsigned long int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_long_long_unsigned(va_list *arg, char *buffer, int **tab, int base)
{
	unsigned long long int i;

	i = va_arg((*arg), unsigned long long int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}
                                                                                                                                              SRC/get_unsigned_2.c                                                                                000644  034027  010202  00000002401 13046061313 016160  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:06:39 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/20 19:36:12 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char	*get_unsigned_max(va_list *arg, char *buffer, int **tab, int base)
{
	uintmax_t i;

	i = va_arg((*arg), uintmax_t);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_size_unsigned(va_list *arg, char *buffer, int **tab, int base)
{
	size_t i;

	i = va_arg((*arg), size_t);
	buffer = ft_convertbase(i, base);
	return (buffer);
}
                                                                                                                                                                                                                                                               SRC/init_pt_tab.c                                                                                   000644  034027  010202  00000005040 13046061313 015562  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pt_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 16:08:04 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/31 11:09:41 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

void	init_pt_tab(char *(**types)(va_list *arg, char *buffer, int **tab,
			t_list *elem))
{
	types[0] = &get_nothing;
	types[1] = &get_int;
	types[2] = &get_octal;
	types[3] = &get_int_ns;
	types[4] = &get_hexa_low;
	types[5] = &get_hexa_up;
	types[6] = &get_double;
	types[7] = &get_scient;
	types[8] = &get_scient_up;
	types[9] = &get_shorter;
	types[10] = &get_shorter_up;
	types[11] = &get_char;
	types[12] = &get_str;
	types[13] = &get_point;
	types[14] = &get_binary;
	types[15] = &get_percent;
	types[16] = &get_long_str;
}

void	init_signed_tab(char *(**modif_signed)
		(va_list *arg, char *buffer, int **tab))
{
	modif_signed[0] = &get_normal_int;
	modif_signed[1] = &get_short_short_int;
	modif_signed[2] = &get_short_int;
	modif_signed[3] = &get_long_int;
	modif_signed[4] = &get_long_long_int;
	modif_signed[5] = &get_int_max;
	modif_signed[6] = &get_size_int;
}

void	init_unsigned_tab(char *(**modif_unsigned)(va_list *arg, char *buffer,
			int **tab, int base))
{
	modif_unsigned[0] = &get_normal_unsigned;
	modif_unsigned[1] = &get_short_short_unsigned;
	modif_unsigned[2] = &get_short_unsigned;
	modif_unsigned[3] = &get_long_unsigned;
	modif_unsigned[4] = &get_long_long_unsigned;
	modif_unsigned[5] = &get_unsigned_max;
	modif_unsigned[6] = &get_size_unsigned;
}

void	init_diez_tab(char *(**diez)(char *tmp, char *buffer, int **tab))
{
	diez[2] = &apply_diez_octal;
	diez[4] = &apply_diez_hexa_low;
	diez[5] = &apply_diez_hexa_up;
	diez[6] = &apply_diez_double;
	diez[7] = &apply_diez_scient_low;
	diez[8] = &apply_diez_scient_low;
	diez[9] = &apply_diez_shorter_low;
	diez[10] = &apply_diez_shorter_low;
	diez[14] = &apply_diez_binary;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                SRC/modif_unicode.c                                                                                 000644  034027  010202  00000004765 13046061313 016107  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
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
           SRC/print_arg.c                                                                                     000644  034027  010202  00000006423 13046061313 015261  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:55:42 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/31 11:10:20 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

void	free_tab(int **tab)
{
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab[3]);
	free(tab[4]);
	free(tab);
}

int		verif_type(int **tab)
{
	if ((tab[4][0] == 11 && tab[3][0] == 3) || tab[4][0] == 16 || (tab[4][0] ==
				12 && tab[3][0] == 3) || tab[3][0] == 14)
		return (0);
	return (1);
}

char	*print_arg(int **tab, va_list *arg, t_list *elem, const char *format)
{
	char	*buffer;
	char	*(*types[17])(va_list *arg, char *buffer, int **tab, t_list *elem);

	ft_putprintf(elem, tab);
	init_pt_tab(types);
	buffer = types[tab[4][0]](arg, buffer, tab, elem);
	free(elem->str);
	if (verif_type(tab))
		buffer = ft_apply_flag(tab, buffer);
	else
		buffer = ft_apply_flag_uni(tab, elem, buffer);
	elem->str = (char *)malloc((ft_strlen(buffer) + ft_strlen(format) + 1)
		* sizeof(char));
	ft_bzero(elem->str, ft_strlen(buffer) + ft_strlen(format) + 1);
	ft_strcpy(elem->str, buffer);
	free(buffer);
	if (tab[0][0] == '-' && !verif_type(tab))
		ft_putunicode(elem, tab);
	ft_putprintf(elem, tab);
	free_tab(tab);
	return (elem->str);
}

char	*ft_add_empty(char *tmp, int **tab, char *buffer)
{
	int		n;
	int		i;
	char	tmp2[tab[1][0] + 1];

	i = 0;
	n = ft_strlen(tmp);
	if (tab[0][0] == '-')
		while (tab[1][0] - n)
			tmp[n++] = tab[0][3];
	else
	{
		ft_bzero(tmp2, tab[1][0] + 1);
		while ((tmp[0] == '-' || tmp[0] == '+' || tmp[0] == '0' || tmp[0] == ' '
					|| tmp[0] == 'x' || tmp[0] == 'X') && tab[0][3] == '0')
		{
			tmp2[i++] = tmp[0];
			ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
			n--;
		}
		while (i < tab[1][0] - n)
			tmp2[i++] = tab[0][3];
		ft_strcat(tmp2, tmp);
		ft_strcpy(tmp, tmp2);
	}
	return (tmp);
}

char	*ft_apply_flag(int **tab, char *buffer)
{
	char	*tmp;
	char	*(*diez[11])(char *tmp, char *buffer, int **tab);

	init_diez_tab(diez);
	if (tab[1][0] > ft_strlen(buffer))
	{
		tmp = (char *)malloc((tab[1][0] + 4) * sizeof(char));
		ft_bzero(tmp, tab[1][0] + 4);
	}
	else
	{
		tmp = (char *)malloc((ft_strlen(buffer) + 4) * sizeof(char));
		ft_bzero(tmp, ft_strlen(buffer) + 4);
	}
	if (tab[1] && ((tab[4][0] >= 6 && tab[4][0] <= 10) || tab[4][0] == 1)
		&& buffer[0] != '-')
		tmp[0] = tab[0][1];
	if (tab[0][2] == '#' && ((tab[4][0] >= 4 && tab[4][0] <= 10) ||
				tab[4][0] == 2 || tab[4][0] == 14))
		buffer = diez[tab[4][0]](tmp, buffer, tab);
	ft_strcat(tmp, buffer);
	free(buffer);
	if (tab[1][0] > ft_strlen(buffer))
		buffer = ft_add_empty(tmp, tab, buffer);
	return (tmp);
}
                                                                                                                                                                                                                                             SRC/second_diez.c                                                                                   000644  034027  010202  00000004106 13046061313 015556  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diez_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:32:10 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:02:50 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"

char		*apply_diez_binary(char *tmp, char *buffer, int **tab)
{
	tmp[0] = '0';
	tmp[1] = 'b';
	return (buffer);
}

char		*apply_diez_shorter_low2(char *tmp, char *buffer, int **tab)
{
	char	str[tab[2][0] + 2];
	int		i;

	i = 0;
	ft_strcpy(str, buffer);
	if (!ft_strchr(str, '.'))
		str[ft_strlen(str)] = '.';
	i = ft_strlen(str) + 1;
	while (i <= tab[2][0])
		str[i++] = '0';
	free(buffer);
	buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_bzero(buffer, ft_strlen(str) + 1);
	ft_strcpy(buffer, str);
	return (buffer);
}

char		*apply_diez_shorter_low(char *tmp, char *buffer, int **tab)
{
	char		str[tab[2][0] + 2];
	int			i;

	i = 0;
	ft_bzero(str, tab[2][0] + 2);
	if (ft_strchr(buffer, 'e'))
	{
		while (buffer[i] != 'e')
		{
			str[i] = buffer[i];
			i++;
		}
		ft_memmove(buffer, buffer + i, ft_strlen(buffer) - i);
		ft_bzero(buffer + 4, ft_strlen(buffer) - 4);
		while (i <= tab[2][0])
			str[i++] = '0';
		ft_strcat(str, buffer);
		free(buffer);
		buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
		ft_bzero(buffer, ft_strlen(str) + 1);
		ft_strcpy(buffer, str);
		return (buffer);
	}
	else
		return (apply_diez_shorter_low2(tmp, buffer, tab));
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                          auteur                                                                                              000644  034027  010202  00000000011 13046061313 013714  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         rfernand
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       libftprintf/                                                                                        000755  034027  010202  00000000000 13046061313 015017  5                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         libftprintf/ft_atoi.c                                                                               000644  034027  010202  00000002617 13046061313 016616  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:06:33 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/02 16:05:30 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int result;

	result = 0;
	while (*str == '\n' || *str == ' ' || *str == '\t' || *str == '\r' ||
			*str == '\v' || *str == '\f')
		str++;
	if (*str != '-' && *str != '+' && (*str < '0' || *str > '9'))
		return (0);
	if (*str == '-')
	{
		str++;
		while (*str >= '0' && *str <= '9' && *str)
			result = result * 10 + *str++ - 48;
		result = -result;
	}
	else
	{
		if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9' && *str)
			result = result * 10 + *str++ - 48;
	}
	return (result);
}
                                                                                                                 libftprintf/ft_bzero.c                                                                              000644  034027  010202  00000001764 13046061313 017005  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:36:07 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/02 16:05:53 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n--)
		*str++ = '\0';
}
            libftprintf/ft_convertbase.c                                                                        000644  034027  010202  00000003056 13046061313 020173  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 15:33:59 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:46:12 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	check_value(int i)
{
	if (i < 10)
		return (i + 48);
	if (i == 10)
		return ('a');
	if (i == 11)
		return ('b');
	if (i == 12)
		return ('c');
	if (i == 13)
		return ('d');
	if (i == 14)
		return ('e');
	if (i == 15)
		return ('f');
	return (0);
}

char	*ft_convertbase(unsigned long long i, int base)
{
	int					n;
	int					u;
	unsigned long long	y;
	char				*str;

	n = 0;
	u = 0;
	y = i;
	if (i == 0)
		return (str = ft_itoa(0));
	while (y >= 1)
	{
		y /= base;
		n++;
	}
	str = (char *)malloc((n + 1) * sizeof(char));
	ft_bzero(str, n + 1);
	while (n--)
	{
		str[u++] = check_value(i / ft_power(base, n));
		i = i % ft_power(base, n);
	}
	return (str);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  libftprintf/ft_dtoa.c                                                                               000644  034027  010202  00000002624 13046061313 016607  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:42:00 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:47:11 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_dtoa(long double i, int size)
{
	long int	n;
	int			u;
	char		*str;
	char		*buffer;

	n = (long int)i;
	buffer = ft_itoa(n);
	str = (char *)malloc((ft_strlen(buffer) + size + 3) * sizeof(char));
	ft_bzero(str, ft_strlen(buffer) + size + 3);
	ft_strcpy(str, buffer);
	free(buffer);
	u = ft_strlen(str);
	if (size > 0)
		str[u++] = '.';
	i = i - (long double)n;
	if (i < 0)
		i = -i;
	while (size-- + 1)
	{
		i = 10 * i;
		n = (int)i;
		str[u++] = n + '0';
		i = i - (long double)n;
	}
	return (str);
}
                                                                                                            libftprintf/ft_itoa.c                                                                               000644  034027  010202  00000003104 13046061313 016606  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:58:14 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:46:26 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_lennb(long n)
{
	int u;

	u = 0;
	if (n < 0)
		u++;
	while (n > 9 || n < -9)
	{
		u++;
		n = n / 10;
	}
	return (u + 1);
}

static char	*negatifvalue(long n)
{
	char	*str;
	int		u;
	int		h;

	u = ft_lennb(n);
	h = u;
	str = (void *)malloc((u + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (u--)
	{
		str[u] = -(n % 10) + 48;
		n = n / 10;
	}
	str[0] = '-';
	str[h] = '\0';
	return (str);
}

char		*ft_itoa(long n)
{
	char	*str;
	long	i;
	int		u;
	int		h;

	i = n;
	u = ft_lennb(n);
	h = u;
	if (n < 0)
		return (negatifvalue(n));
	str = (void *)malloc((u + 1) * sizeof(char));
	while (u--)
	{
		str[u] = n % 10 + 48;
		n = n / 10;
	}
	str[h] = '\0';
	return (str);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                            libftprintf/ft_memalloc.c                                                                           000644  034027  010202  00000002067 13046061313 017452  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                         libftprintf/ft_memcpy.c                                                                             000644  034027  010202  00000002165 13046061313 017152  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:42:42 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/18 19:15:10 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*str;
	unsigned char		*cpy;
	int					i;

	str = src;
	cpy = dst;
	i = n;
	while (n--)
		*cpy++ = *str++;
	return (cpy - i);
}
                                                                                                                                                                                                                                                                                                                                                                                                           libftprintf/ft_memmove.c                                                                            000644  034027  010202  00000002201 13046061313 017314  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
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
                                                                                                                                                                                                                                                                                                                                                                                               libftprintf/ft_power.c                                                                              000644  034027  010202  00000001761 13046061313 017015  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:57:49 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/20 19:28:49 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_power(long long i, int power)
{
	if (power == 0)
		return (1);
	return (i * ft_power(i, power - 1));
}
               libftprintf/ft_putchar.c                                                                            000644  034027  010202  00000001677 13046061313 017335  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:20:54 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/02 16:06:06 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
                                                                 libftprintf/ft_putnbr.c                                                                             000644  034027  010202  00000002212 13046061313 017163  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:20:54 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/02 16:06:21 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

void	ft_putnbr(int i)
{
	if (i == -2147483648)
	{
		ft_putnbr(-214748364);
		i = 8;
	}
	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + 48);
}
                                                                                                                                                                                                                                                                                                                                                                                      libftprintf/ft_putstr.c                                                                             000644  034027  010202  00000001762 13046061313 017223  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:20:54 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/02 16:06:35 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

void	ft_putstr(char const *str)
{
	while (*str)
		ft_putchar(*str++);
}
              libftprintf/ft_strcat.c                                                                             000644  034027  010202  00000002050 13046061313 017151  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:43:53 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/02 16:11:12 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!*s2)
		return (s1);
	while (s1[i])
		i++;
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        libftprintf/ft_strchr.c                                                                             000644  034027  010202  00000002042 13046061313 017157  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:54:14 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/20 14:36:09 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s - 1 && *s == c)
		return ((char*)s);
	else
		return (NULL);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              libftprintf/ft_strcpy.c                                                                             000644  034027  010202  00000002005 13046061313 017175  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:21:39 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/02 16:06:39 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char *str;

	str = dst;
	while (*src)
		*str++ = *src++;
	*str++ = '\0';
	return (dst);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           libftprintf/ft_strlen.c                                                                             000644  034027  010202  00000001751 13046061313 017167  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:53:59 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/02 16:06:50 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
                       libftprintf/ft_toupper.c                                                                            000644  034027  010202  00000001731 13046061313 017354  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:01:12 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/04 16:51:05 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
                                       libftprintf/ft_utoa.c                                                                               000644  034027  010202  00000002414 13046061313 016625  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:48:37 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 14:44:47 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_lennb(unsigned int n)
{
	int u;

	u = 0;
	while (n > 9)
	{
		u++;
		n = n / 10;
	}
	return (u + 1);
}

char		*ft_utoa(unsigned int n)
{
	char				*str;
	unsigned int		i;
	int					u;
	int					h;

	i = n;
	u = ft_lennb(n);
	h = u;
	str = (char *)malloc((u + 1) * sizeof(char));
	while (u--)
	{
		str[u] = n % 10 + 48;
		n = n / 10;
	}
	str[h] = '\0';
	return (str);
}
                                                                                                                                                                                                                                                    libftprintf/libftprintf.h                                                                           000644  034027  010202  00000014623 13046061313 017521  0                                                                                                    ustar 00rfernand                        2015_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:26:16 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/16 14:59:26 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_list
{
	char			*str;
	int				aff_nul;
	int				aff_nul_uni;
	int				i;
	wchar_t			*unicode;
	unsigned char	o3;
	unsigned char	o4;
}					t_list;

void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				ft_putchar(char c);
void				ft_putnbr(int i);
void				ft_putstr(char const *str);
int					ft_atoi(const char *str);
char				*ft_itoa(long n);
int					ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
void				ft_bzero(void *s, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
long long			ft_power(long long i, int power);
char				*ft_utoa(unsigned int n);
char				*ft_convertbase(unsigned long long i, int base);
int					ft_toupper(int c);
char				*ft_dtoa(long double i, int size);
char				*ft_round(char *str, int size);
int					size_forscient(double *i);
int					size_forscient_long(long double *i);
char				*arg_forscient(char *buffer, int n);
char				*arg_forscient_up(char *buffer, int n);
char				*fill_point(char *buffer, int **tab);
char				*ft_addzero(char *str, int size);
void				ft_delete_zero(char *str);
int					ft_putprintf(t_list *elem, int **tab);
void				ft_putunicode(t_list *elem, int **tab);
int					ft_wstrlen(wchar_t *unicode);

char				*print_arg(int **tab, va_list *arg, t_list *elem,
					const char *format);
int					**check_format(va_list *arg, const char *format, int *i);

void				check_flags(int *tab, const char *format, int *i);
void				check_len(va_list *arg, int **tab, const char *format,
					int *i);
int					check_accuracy(va_list *arg, int **tab, const char *format,
					int *i);
void				check_modif(int *tab, const char *format, int *i);
int					check_type(int **tab, char c);

void				init_pt_tab(char *(**types)(va_list *arg, char *buffer,
					int **tab, t_list *elem));
void				init_signed_tab(char *(**modif_signed)
					(va_list *arg, char *buffer, int **tab));
void				init_unsigned_tab(char *(**modif_unsigned)
					(va_list *arg, char *buffer, int **tab, int base));
void				init_diez_tab(char *(**diez)(char *tmp, char *buffer,
					int **tab));
int					ft_printf(const char *format, ...);

char				*get_nothing(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_int(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_octal(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_int_ns(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_hexa_low(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_hexa_up(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_double(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_char(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_str(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_scient(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_scient_up(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_point(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_shorter(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_shorter_up(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_binary(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_percent(va_list *arg, char *buffer, int **tab,
					t_list *elem);
char				*get_long_str(va_list *arg, char *buffer, int **tab,
					t_list *elem);

char				*get_short_short_int(va_list *arg, char *buffer, int **tab);
char				*get_short_int(va_list *arg, char *buffer, int **tab);
char				*get_normal_int(va_list *arg, char *buffer, int **tab);
char				*get_long_int(va_list *arg, char *buffer, int **tab);
char				*get_long_long_int(va_list *arg, char *buffer, int **tab);
char				*get_int_max(va_list *arg, char *buffer, int **tab);
char				*get_size_int(va_list *arg, char *buffer, int **tab);

char				*get_short_short_unsigned(va_list *arg, char *buffer,
					int **tab, int base);
char				*get_short_unsigned(va_list *arg, char *buffer, int **tab,
					int base);
char				*get_normal_unsigned(va_list *arg, char *buffer, int **tab,
					int base);
char				*get_long_unsigned(va_list *arg, char *buffer, int **tab,
					int base);
char				*get_long_long_unsigned(va_list *arg, char *buffer,
					int **tab, int base);
char				*get_unsigned_max(va_list *arg, char *buffer, int **tab,
					int base);
char				*get_size_unsigned(va_list *arg, char *buffer, int **tab,
					int base);

char				*ft_apply_flag(int **tab, char *buffer);
char				*ft_apply_flag_uni(int **tab, t_list *elem, char *buffer);
char				*apply_diez_octal(char *tmp, char *buffer, int **tab);
char				*apply_diez_hexa_low(char *tmp, char *buffer, int **tab);
char				*apply_diez_hexa_up(char *tmp, char *buffer, int **tab);
char				*apply_diez_double(char *tmp, char *buffer, int **tab);
char				*apply_diez_scient_low(char *tmp, char *buffer, int **tab);
char				*apply_diez_shorter_low(char *tmp, char *buffer, int **tab);
char				*apply_diez_binary(char *tmp, char *buffer, int **tab);

int					ft_size(wchar_t value);
int					ft_size_octet(wchar_t unicode);
void				apply_accuracy_wchar(t_list *elem, int **tab);
void				one_octet(t_list *elem, wchar_t unicode);
void				two_octet(t_list *elem, wchar_t unicode);
void				three_octet(t_list *elem, wchar_t unicode);
void				four_octet(t_list *elem, wchar_t unicode);

#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             