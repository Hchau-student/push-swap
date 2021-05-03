/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:51:00 by hchau             #+#    #+#             */
/*   Updated: 2019/04/19 10:46:31 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	new_norme_costil(char const *nb, int i, long a, long s)
{
	while (*nb)
	{
		if (*nb >= '0' && *nb <= '9')
		{
			if ((a > s || (a == s && *nb >= '8')) && i == 1)
				return (-1);
			if ((a > s || (a == s && *nb >= '9')) && i == -1)
				return (0);
			a = (*nb++ - '0') + a * 10;
		}
		else
			return (a * i);
	}
	return (a * i);
}

int	ft_atoi(char const *nb)
{
	long	a;
	int		i;
	long	s;

	a = 0;
	i = 1;
	s = 214748364;
	while (*nb && ((*nb >= 9 && *nb <= 13) || *nb == 32))
		nb += 1;
	if (*nb == '+' || *nb == '-')
	{
		if (*nb++ == '-')
			i = -1;
		else
			i = 1;
	}
	return (new_norme_costil(nb, i, a, s));
}
