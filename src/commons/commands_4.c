//
// Created by Hugor Chau on 3/27/21.
//

/*
 * ra : rotate a - shift up all elements of
 * stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of
 stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.
*/

#include "header.h"

void	ra(t_stack *rotate)
{
	t_node		*tmp;
	t_node		*new_begin;

	if (rotate->size <= 1)
		return ;
	if (rotate->begin == NULL || rotate->end == NULL)
		return ;
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

void	rb(t_stack *rotate)
{
	t_node		*tmp;
	t_node		*new_begin;

	if (rotate->size <= 1)
		return ;
	if (rotate->begin == NULL || rotate->end == NULL)
		return ;
	tmp = rotate->begin;
	rotate->begin = rotate->begin->prev;
	new_begin = tmp->prev;
	new_begin->next = tmp->next;
	new_begin->next->prev = new_begin;
	tmp->next = rotate->end;
	tmp->prev = rotate->end->prev;
	rotate->end->prev = tmp;
	tmp->prev->next = tmp;
	rotate->end = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
