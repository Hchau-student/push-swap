#include "header.h"

void	perform_single_command(unsigned int count, t_stack *stack,
							   t_command command)
{
	while (count)
	{
		exec(command, stack);
		count--;
	}
}

void	perform_both_commands(unsigned int count, t_stack *a, t_stack *b,
								t_command command)
{
	while (count)
	{
		exec_2(command, a, b);
		count--;
	}
}

int	both_commands(unsigned int *a, unsigned int *b)
{
	unsigned int	res;

	if (*a > *b)
		res = *a - *b;
	else
		res = *b - *a;
	if (res > *b || res > *a)
		return (0);
	*a = *a - res;
	*b = *b - res;
	return (res);
}

/*
 * need to find elem with shortest commands list
 * */

t_node	*find_list(t_stack *a, t_stack *b)
{
	t_iter				*iter;
	unsigned int		i;
	unsigned int		min;
	unsigned int		cur;
	t_node				*res;

	i = 0;
	iter = new_iter(b);
	cur = MAX_INT;
	min = MAX_INT;
	res = b->begin;
	while (i < b->size)
	{
		cur = count_element_a(a, b, iter->cur);
		if (cur < min)
		{
			min = cur;
			res = iter->cur;
		}
		iter->next_iter(iter);
		i++;
	}
	destroy_iter(&iter);
	return (res);
}

void	choose_element(t_stack *a, t_stack *b)
{
	unsigned int		ra_count;
	unsigned int		rra_count;
	unsigned int		rb_count;
	unsigned int		rrb_count;
	t_node				*lst;

	ra_count = 0;
	rra_count = 0;
	rb_count = 0;
	rrb_count = 0;
	lst = find_list(a, b);
	count_commands_a(&ra_count, &rra_count, a, lst);
	count_commands_b(&rb_count, &rrb_count, b, lst);
	perform_both_commands(both_commands(&ra_count, &rb_count), a, b, command(RR));
	perform_both_commands(both_commands(&rra_count, &rrb_count), a, b, command(RRR));
	perform_single_command(ra_count, a, command(RA));
	perform_single_command(rra_count, a, command(RRA));
	perform_single_command(rb_count, b, command(RB));
	perform_single_command(rrb_count, b, command(RRB));
}
