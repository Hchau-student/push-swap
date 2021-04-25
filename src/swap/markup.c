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
		{
			tmp->markup_greater = TRUE;
		}
		else
			tmp->markup_greater = FALSE;
		i++;
	}
	destroy_iter(&iter);
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
		if (iter->cur->markup_greater == TRUE)
			curr_len++;
		else
		{
			tmp = iter->cur;
			curr_len = 0;
		}
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
	t_iter				*iter;

	i = 0;
	iter = new_iter(a);
	tmp = a->begin;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size - 1)
		{
			if (tmp->val > iter->cur->next->val)
				tmp->index++;
			j++;
			iter->next_iter(iter);
		}
		tmp = tmp->next;
		i++;
	}
	destroy_iter(&iter);
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
		if (iter->cur->markup_greater == TRUE)
			curr_len++;
		else
		{
			tmp = iter->cur;
			curr_len = 0;
		}
		if (curr_len >= max_len)
		{
			max_len = curr_len;
		}
		iter->next_iter(iter);
		i++;
	}
	destroy_iter(&iter);
	return (max_len);
}
