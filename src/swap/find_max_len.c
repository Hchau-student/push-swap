#include "header.h"

static void	if_case(t_iter *iter, unsigned int *curr_len, t_node **tmp)
{
	if (iter->cur->markup_greater == TRUE)
		*(curr_len) = *curr_len + 1;
	else
	{
		*tmp = iter->cur;
		*curr_len = 0;
	}
}

unsigned int	find_max_len(t_stack *stack)
{
	unsigned int		i;
	unsigned int		max_len;
	unsigned int		curr_len;
	t_node				*tmp;
	t_iter				*iter;

	i = 0;
	curr_len = 0;
	max_len = 0;
	tmp = stack->begin;
	markup_greater(stack);
	iter = new_iter(stack);
	while (i < stack->size)
	{
		if_case(iter, &curr_len, &tmp);
		if (curr_len >= max_len)
			max_len = curr_len;
		iter->next_iter(iter);
		i++;
	}
	destroy_iter(&iter);
	return (max_len);
}
