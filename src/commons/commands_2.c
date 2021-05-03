//
// Created by Hugor Chau on 3/27/21.
//

#include "swap.h"

/*
** pa : push a - take the first element at the
** top of b and put it at the top of a. Do
** nothing if b is empty.
**
** pb : push b - take the first element at the
** top of a and put it at the top of b. Do
** nothing if a is empty.
 */

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	if (a->size == 0)
	{
		a->begin = b->begin;
		a->end = b->begin;
	}
	else
	{
		a->begin = b->begin;
	}
	b->size--;
	a->size++;
	b->begin = b->begin->prev;
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	if (b->size == 0)
	{
		b->begin = a->begin;
		b->end = a->begin;
	}
	else
	{
		b->begin = a->begin;
	}
	a->size--;
	b->size++;
	a->begin = a->begin->next;
}
