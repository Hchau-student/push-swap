#include "swap.h"

/*
**  sa : swap a - swap the first 2 elements at the top of stack
**  a. Do nothing if there
**  is only one or no elements).
**  sb : swap b - swap the first 2 elements at
**  the top of stack b. Do nothing if there
**  is only one or no elements).
**  ss : sa and sb at the same time.
*/

//1) function that swaps 2 lists (for pa/pb/sa)

static void	swap_val(t_node *a, t_node *b)
{
	t_val				tmp;
	unsigned int		tmp_index;
	char				tmp_markup_greater;
	char				tmp_markup_index;

	tmp = a->val;
	a->val = b->val;
	b->val = tmp;
	tmp_index = a->index;
	a->index = b->index;
	b->index = tmp_index;
	tmp_markup_greater = a->markup_greater;
	a->markup_greater = b->markup_greater;
	b->markup_greater = tmp_markup_greater;
	tmp_markup_index = a->markup_index;
	a->markup_index = b->markup_index;
	b->markup_index = tmp_markup_index;
}

void	sa(t_stack *a)
{
	if (a->size <= 1)
		return ;
	if (a->begin == NULL || a->begin->prev == NULL)
		return ;
	swap_val(a->begin, a->begin->next);
}

void	sb(t_stack *b)
{
	if (b->size <= 1)
		return ;
	if (b->begin == NULL || b->begin->prev == NULL)
		return ;
	swap_val(b->begin, b->begin->prev);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
