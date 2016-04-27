/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:55:42 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/27 18:07:15 by rfernand         ###   ########.fr       */
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

int			verif_type(int **tab)
{
	if (tab[4][0] == 11 || tab[4][0] == 16 || (tab[4][0] == 12 
				&& tab[3][0] == 3))
		return (0);
	return (1);
}

char		*print_arg(int **tab, va_list *arg, t_list *elem, const char *format)
{
	char *buffer;
	char *buf;
	int n;
	char	*(*types[17])(va_list *arg, char *buffer, int **tab);

	n = ft_strlen(elem->str);
	buf = (char *)malloc((n + 1) * sizeof(char));
	ft_strcpy(buf, elem->str);
	init_pt_tab(types);
	buffer = types[tab[4][0]](arg, buffer, tab);
	free (elem->str);
	if (verif_type(tab))
		buffer = ft_apply_flag(tab, buffer);
/*	else
		elem->unicode = ft_apply_flag_uni(tab, elem);
*/	elem->str = (char *) malloc((n + ft_strlen(buffer) + ft_strlen(format) + 1) 
		* sizeof (char));
	ft_bzero(elem->str, n + ft_strlen(buffer) + ft_strlen(format) + 1);
	ft_strcpy(elem->str, buf);
	free(buf);
	ft_strcat(elem->str, buffer);
	free(buffer);
	ft_putprintf(elem, tab);
	free_tab(tab);
	return (elem->str);
}

char		*ft_add_empty(char *tmp, int **tab, char *buffer)
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
	return(tmp);
}

char		*ft_apply_flag(int **tab, char *buffer)
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
	return(tmp);
}
