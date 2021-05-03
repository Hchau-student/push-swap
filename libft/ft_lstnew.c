/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:33:23 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:40:27 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	if (content == NULL)
	{
		newlist->content_size = 0;
		newlist->content = NULL;
	}
	else
	{
		newlist->content = malloc((sizeof(content)) * (content_size));
		if (!(newlist->content))
		{
			free(newlist);
			newlist = NULL;
			return (NULL);
		}
		newlist->content_size = content_size;
		newlist->content = ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
