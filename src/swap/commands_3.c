//
// Created by Hugor Chau on 3/27/21.
//

/*
 * ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.
*/

#include "header.h"

static void		r(t_stack *rotate)
{
	t_node		*tmp;
	t_node		*new_end;

	if (rotate->size <= 1)
		return;
	if (rotate->begin == NULL || rotate->end == NULL)
		return;
	tmp = rotate->end;

	new_end = tmp->prev;
	rotate->end = new_end;

	new_end->next = tmp->next;
	new_end->next->prev = new_end;

	tmp->next = rotate->begin;
	tmp->prev = rotate->begin->prev;

	rotate->begin->prev = tmp;

	tmp->prev->next = tmp;
	rotate->begin = tmp;
	rotate->cur = rotate->begin;
}

void		ra(t_stack *a)
{
	r(a);
	ft_putendl("ra");
}

void		rb(t_stack *b)
{
	r(b);
	ft_putendl("rb");
}

void		rr(t_stack *a, t_stack *b)
{
	r(a);
	r(b);
	ft_putendl("rr");
}
