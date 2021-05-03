/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:32:13 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:37:42 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*new;
	t_list		*head;

	if (!f || !lst)
		return (NULL);
	tmp = f(lst);
	head = ft_lstnew(tmp->content, tmp->content_size);
	new = head;
	head->next = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!(new->next))
		{
			ft_lstclr(&lst);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
