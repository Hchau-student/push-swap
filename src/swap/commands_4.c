//
// Created by Hugor Chau on 3/27/21.
//

/*
 * rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.
*/

#include "header.h"

static void		r(t_stack *rotate)
{
	t_node		*tmp;
	t_node		*new_begin;

	if (rotate->size <= 1)
		return;
	if (rotate->begin == NULL || rotate->end == NULL)
		return;
	tmp = rotate->begin;
	rotate->begin = rotate->begin->next;
	new_begin = tmp->next;
	new_begin->prev = tmp->prev;
	new_begin->prev->next = new_begin;
	tmp->prev = rotate->end;
	tmp->next = rotate->end->next;
	rotate->end->next = tmp;
	tmp->next->prev = tmp;
	rotate->end = tmp;
}

void		rra(t_stack *a)
{
	r(a);
}

void		rrb(t_stack *b)
{
	r(b);
}

void		rrr(t_stack *a, t_stack *b)
{
	r(a);
	r(b);
}
