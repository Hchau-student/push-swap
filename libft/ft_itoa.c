/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:09:46 by hchau             #+#    #+#             */
/*   Updated: 2019/04/22 11:16:23 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	new_norme_costil(size_t *i, int n)
{
	if (n < 0)
		*i = *i + 1;
}

static void	*new_norme_costil2(char **res, size_t i)
{
	*res = ft_strnew(i);
	return (res);
}

static void	new_norme_costil3(long *a, char *res)
{
	if (*a < 0)
	{
		res[0] = '-';
		*a = *a * -1;
	}
}

char	*ft_itoa(int n)
{
	char		*res;
	size_t		i;
	long		a;

	a = n;
	i = 1;
	new_norme_costil(&i, n);
	while (n != 0 && (i + 1) > 0)
	{
		n = n / 10;
		i++;
	}
	if (!(new_norme_costil2(&res, i)))
		return (NULL);
	if (a == 0)
		res[0] = '0';
	new_norme_costil3(&a, res);
	while (a != 0)
	{
		res[--i] = a % 10 + 48;
		a = a / 10;
	}
	return (res);
}
