//
// Created by Hugor Chau on 3/28/21.
//

#include "header.h"

void		markup_index(t_stack *stack)
{
	unsigned int		i;

	i = 0;
	stack->cur->markup_greater = TRUE;
	while (i < stack->size - 1)
	{
		if (stack->cur->index + 1 == stack->cur->next->index)
		{
			stack->cur->next->markup_greater = TRUE;
		}
		else
			stack->cur->next->markup_greater = FALSE;
		stack->next(stack);
		i++;
	}
}

void		markup_greater(t_stack *stack)
{
	unsigned int		i;

	i = 0;
	stack->cur->markup_greater = TRUE;
	while (i < stack->size - 1)
	{
		if (stack->cur < stack->cur->next)
		{
			stack->cur->next->markup_greater = TRUE;
		}
		else
			stack->cur->next->markup_greater = FALSE;
		stack->next(stack);
		i++;
	}
}

void		find_markup_head(t_stack *stack)
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
		if (stack->cur->markup_greater == TRUE)
			curr_len++;
		else
		{
			tmp = stack->cur;
			curr_len = 0;
		}
		if (curr_len >= max_len)// > max_len)
		{
			stack->max_len_greater = tmp;
			max_len = curr_len;
		}
//		if (curr_len == max_len && stack->max_len_greater->index > tmp->index)
//			stack->max_len_greater = tmp;
		stack->next(stack);
		i++;
	}
	stack->cur = stack->begin;
}

void		indexing(t_stack *a)
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
}
