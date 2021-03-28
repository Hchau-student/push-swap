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
