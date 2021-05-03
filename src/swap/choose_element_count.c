#include "swap.h"

int	right_position(t_iter *iter, t_iter *prev_iter, t_node *elem)
{
	if (prev_iter->cur->val > iter->cur->val)
	{
		if (elem->val < iter->cur->val
			|| elem->val > prev_iter->cur->val)
			return (TRUE);
	}
	if (iter->cur->val > elem->val && prev_iter->cur->val < elem->val)
		return (TRUE);
	return (FALSE);
}

void	chose_direction(unsigned int *rot, unsigned int *rev_rot)
{
	if (*rot < *rev_rot)
		*rev_rot = 0;
	else
		*rot = 0;
}

void	count_commands_a(unsigned int *rota, unsigned int *rrota,
						t_stack *stack, t_node *elem)
{
	unsigned int		i;
	t_iter				*iter;
	t_iter				*prev_iter;

	i = 0;
	*rrota = stack->size;
	*rota = 0;
	iter = new_iter(stack);
	prev_iter = new_iter(stack);
	prev_iter->prev(prev_iter);
	while (i < stack->size)
	{
		if (right_position(iter, prev_iter, elem) == TRUE)
			break ;
		*rota = *rota + 1;
		*rrota = *rrota - 1;
		iter->next_iter(iter);
		prev_iter->next_iter(prev_iter);
		i++;
	}
	chose_direction(rota, rrota);
	destroy_iter(&iter);
	destroy_iter(&prev_iter);
}

void	count_commands_b(unsigned int *rrota, unsigned int *rota,
						t_stack *b, t_node *elem)
{
	t_iter				*iter;
	unsigned int		i;

	iter = new_iter(b);
	*rrota = 0;
	i = 0;
	*rota = b->size;
	while (i < b->size && iter->cur != elem)
	{
		*rrota = *rrota + 1;
		*rota = *rota - 1;
		iter->next_iter(iter);
		i++;
	}
	chose_direction(rota, rrota);
	destroy_iter(&iter);
}

unsigned int	count_element_a(t_stack *a, t_stack *b, t_node *node)
{
	unsigned int		ra_count;
	unsigned int		rra_count;
	unsigned int		rb_count;
	unsigned int		rrb_count;

	ra_count = 0;
	rra_count = 0;
	rb_count = 0;
	rrb_count = 0;
	count_commands_a(&ra_count, &rra_count, a, node);
	count_commands_b(&rb_count, &rrb_count, b, node);
	return (ra_count + rra_count + rb_count + rrb_count);
}
