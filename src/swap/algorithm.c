//
// Created by Hugor Chau on 3/28/21.
//

#include "header.h"

void			recount_stack(t_stack *stack)
{
	unsigned int		i;
	unsigned int		max_len;
	unsigned int		curr_len;
	t_node				*tmp;

	i = 0;
	curr_len = 0;
	max_len = 0;
	tmp = stack->begin;
	while (i < stack->size)
	{
		if (curr_len > max_len)
			max_len = curr_len;
		i++;
		if (stack->cur->markup_greater == TRUE)
		{
			curr_len++;
			stack->max_len_greater = tmp;
		}
		else
		{
			tmp = stack->cur;
			curr_len = 0;
		}
		stack->next(stack);
	}
	stack->cur = stack->begin;
}

void		prepare_stacks(t_stack *a, t_stack *b)
{
	unsigned int		i;
	unsigned int		j;
	t_node				*tmp;

	i = 0;
	tmp = a->begin;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size - 1)
		{
			if (tmp->val > a->cur->next->val)
				tmp->index++;
			j++;
			a->next(a);
		}
		tmp = tmp->next;
		i++;
	}
	a->cur = a->begin;
//	while (a->size > 2 || recount_stack(a))
//	{
//		pb(a, b);
//	}
}

void		main_cycle(t_stack *a, t_stack *b)
{
	//1) проиндексировать 10 цифр сверху и 10 цифр снизу стека б
}