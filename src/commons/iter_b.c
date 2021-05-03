#include "swap.h"

t_node	*prev_iter_b(t_iter *iter)
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

t_node	*next_iter_b(t_iter *iter)
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
