#include "header.h"

void	markup_index(t_stack *stack)
{
	unsigned int		i;
	t_iter				*iter;

	i = 0;
	iter = new_iter(stack);
	iter->cur->markup_greater = TRUE;
	while (i < stack->size - 1)
	{
		if (iter->cur->index + 1 == iter->cur->next->index)
		{
			iter->cur->next->markup_greater = TRUE;
		}
		else
			iter->cur->next->markup_greater = FALSE;
		iter->next_iter(iter);
		i++;
	}
	destroy_iter(&iter);
}

void	markup_greater(t_stack *stack)
{
	unsigned int		i;
	t_node				*tmp;
	t_node				*tmp_next;
	t_iter				*iter;

	i = 0;
	iter = new_iter(stack);
	while (i < stack->size)
	{
		tmp = iter->cur;
		iter->next_iter(iter);
		tmp_next = iter->cur;
		if (tmp->val < tmp_next->val)
			tmp->markup_greater = TRUE;
		else
			tmp->markup_greater = FALSE;
		i++;
	}
	destroy_iter(&iter);
}

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

void	find_markup_head(t_stack *stack)
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
	iter = new_iter(stack);
	while (i < stack->size)
	{
		if_case(iter, &curr_len, &tmp);
		if (curr_len >= max_len)
		{
			stack->max_len_greater = tmp;
			max_len = curr_len;
		}
		iter->next_iter(iter);
		i++;
	}
	destroy_iter(&iter);
}

void	indexing(t_stack *a)
{
	unsigned int		i;
	unsigned int		j;
	t_node				*tmp;
	t_node				*tmp2;

	i = 0;
	tmp = a->begin;
	while (i < a->size)
	{
		j = 0;
		tmp2 = tmp;
		while (j < a->size)
		{
			if (tmp->val > tmp2->val)
				tmp->index++;
			j++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		i++;
	}
}
