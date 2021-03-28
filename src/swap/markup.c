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
