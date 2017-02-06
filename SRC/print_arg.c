/* ************************************************************************** */
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
