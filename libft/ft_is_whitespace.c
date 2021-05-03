/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:30:56 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:31:11 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_whitespace(int c)
{
	if (c == ' ' || c == '\n' || c == '\r'
		|| c == '\t')
		return (1);
	return (0);
}
