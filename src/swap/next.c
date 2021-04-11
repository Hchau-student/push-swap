//
// Created by Hugor Chau on 4/11/21.
//

#include "header.h"

t_node	*next_a(t_stack *a)
{
	static unsigned int		size = 1;

//	ft_putstr("size in next: ");
//	ft_putnbr(size);
//	ft_putstr("\n");
	if (size >= a->size)
	{
		a->cur = a->begin;
		size = 1;
		return (a->cur);
	}
	size++;
	a->cur = a->cur->next;
	return (a->cur);
}

t_node	*next_b(t_stack *b)
{
	static unsigned int		size = 1;

	if (size >= b->size)
	{
		b->cur = b->begin;
		size = 1;
		return (b->cur);
	}
	size++;
	b->cur = b->cur->prev;
	return (b->cur);
}
