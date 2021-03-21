#include "header.h"

/*
 * sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.
 */

//1) function that swaps 2 lists (for pa/pb/sa)

void		swap_val(t_node *a, t_node *b)
{
	t_val		tmp;

	tmp = a->val;
	a->val = b->val;
	b->val = tmp;
}

void		sa(t_stack *a)
{
	if (a->size <= 1)
		return;
	if (a->begin == NULL || a->begin->next == NULL)//чекнуть все ошибки
		return;
	swap_val(a->begin, a->begin->next);
}

void		ss(t_stack *a, t_stack *b)
{
	sa(a);
	sa(b);
}

//pa : push a - take the first element at the top of b and put it at the top of a. Do
//nothing if b is empty.

void		pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return;
	b->size--;
	b->begin = b->begin->next;
	a->begin = a->begin->prev;
}
