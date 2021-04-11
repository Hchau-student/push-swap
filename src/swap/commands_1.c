#include "header.h"

/*
 * sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
ss : sa and sb at the same time.
*/

//1) function that swaps 2 lists (for pa/pb/sa)

static void		swap_val(t_node *a, t_node *b)
{
	t_val		tmp;

	tmp = a->val;
	a->val = b->val;
	b->val = tmp;
}

void			sa(t_stack *a)
{
	if (a->size <= 1)
		return;
	if (a->begin == NULL || a->begin->next == NULL)//чекнуть все ошибки
		return;
	swap_val(a->begin, a->begin->next);
	ft_putendl("sa");
}

void			sb(t_stack *b)
{
	if (b->size <= 1)
		return;
	if (b->begin == NULL || b->begin->next == NULL)//чекнуть все ошибки
		return;
	swap_val(b->begin, b->begin->next);
	ft_putendl("sb");
}

void			ss(t_stack *a, t_stack *b)
{
	sa(a);
	sa(b);
	ft_putendl("ss");
}
