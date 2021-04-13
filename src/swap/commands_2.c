//
// Created by Hugor Chau on 3/27/21.
//

#include "header.h"

/*
 * pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
 */

void			pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return;
	b->size--;
	a->size++;
	b->begin = b->begin->prev;
	a->begin = a->begin->prev;
//	ft_putendl("pa");
}

void			pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return;
	a->size--;
	b->size++;
	a->begin = a->begin->next;
	b->begin = b->begin->next;
//	ft_putendl("pb");
}
