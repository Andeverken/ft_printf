/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:45:34 by rfernand          #+#    #+#             */
/*   Updated: 2016/03/24 19:03:15 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_flags(int *tab, const char *format, int *i)
{
	int n;

	n = 0;
	while (format[*i] == '-' || format[*i] == '+' || format[*i] == ' ' ||
			format[*i] == '#')
	{
		n = 1;
		if (format[*i] == '-')
			tab[1] = 1;
		if (format[*i] == '+')
			tab[2] = 1;
		if (format[*i] == ' ')
			tab[3] = 1;
		if (format[*i] == '#')
			tab[4] = 1;
		(*i)++;
	}
	if (!n)
		tab[0] = 1;
}
