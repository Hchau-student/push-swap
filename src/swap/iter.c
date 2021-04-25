//
// Created by Hugor Chau on 4/13/21.
//

#include "header.h"

t_iter			*new_iter(t_stack *stack)
{
	t_iter			*iter;

	iter = (t_iter *)malloc(sizeof(t_iter));
	if (iter == NULL)
		return (NULL);
	iter->begin = &(stack->begin);
	iter->end = &(stack->end);
	iter->cur = stack->begin;
	iter->cur_size = 1;
	iter->max_size = &stack->size;
	iter->next_iter = stack->next_iter;
	iter->prev = stack->prev_iter;
	return (iter);
}

void		destroy_iter(t_iter **iter)
{
	if (!iter || !*iter)
		return ;
	free(*iter);
	*iter = NULL;
}

t_node		*next_iter_a(t_iter *iter)
{
	if (iter->cur_size >= *(iter->max_size) || *(iter->end) == iter->cur)
	{
		iter->cur = *(iter->begin);
		iter->cur_size = 1;
		return (iter->cur);
	}
	iter->cur_size++;
	iter->cur = iter->cur->next;
	return (iter->cur);
}

t_node		*next_iter_b(t_iter *iter)
{
	if (iter->cur_size >= *(iter->max_size))
	{
		iter->cur = *(iter->begin);
		iter->cur_size = 1;
		return (iter->cur);
	}
	iter->cur_size++;
	iter->cur = iter->cur->prev;
	return (iter->cur);
}

t_node		*prev_iter_a(t_iter *iter)
{
	if (iter->cur_size <= 1)
	{
		iter->cur = *(iter->end);
		iter->cur_size = 1;
		return (iter->cur);
	}
	iter->cur_size++;
	iter->cur = iter->cur->prev;
	return (iter->cur);
}

t_node		*prev_iter_b(t_iter *iter)
{
	if (iter->cur_size <= 1)
	{
		iter->cur = *(iter->end);
		iter->cur_size = 1;
		return (iter->cur);
	}
	iter->cur_size++;
	iter->cur = iter->cur->next;
	return (iter->cur);
}
