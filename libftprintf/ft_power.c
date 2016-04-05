/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:57:49 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/02 15:54:43 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int i, int power)
{
	if (power == 0)
		return (1);
	return (i * ft_power(i, power - 1));
}