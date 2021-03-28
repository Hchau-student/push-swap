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
		if (stack->cur->markup_greater == TRUE)
			curr_len++;
		else
		{
			tmp = stack->cur;
			curr_len = 0;
		}
		if (curr_len > max_len)
		{
			stack->max_len_greater = tmp;
			max_len = curr_len;
		}
		if (curr_len == max_len && stack->max_len_greater->index > tmp->index)
			stack->max_len_greater = tmp;
		stack->next(stack);
		i++;
	}
	stack->cur = stack->begin;
}

int			sorted(t_stack *a)
{
	unsigned int		i;

	i = 0;
	if (a->begin->index != 0)
		return (FALSE);
	while (i < a->size)
	{
		if (a->cur == a->end)
			break ;
		if (a->cur->index != a->cur->next->index - 1)
			return (FALSE);
		i++;
		a->next(a);
	}
	a->cur = a->begin;
	return (TRUE);
}

void		main_cycle(t_stack *a, t_stack *b)
{
	unsigned int			main_size;

	main_size = a->size;
	indexing(a);
	if (sorted(a))
		return ;
	while (a->size > 2)// || a->max_len_greater != a->begin)
	{
		pb(a, b);
	}
	while (a->size != main_size && !sorted(a))
	{

//		1)IF sa (swap a) is needed
//            perform sa (swap a) command
//            update markup
//      ELSE IF head element of stack A has "false" value in "Keep in Stack A" field
//            perform pb (push b) command
//      ELSE
//            perform ra (rotate a) command
	}
//	1) проиндексировать 10 цифр сверху и 10 цифр снизу стека б
}