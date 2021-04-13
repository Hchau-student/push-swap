//
// Created by Hugor Chau on 4/11/21.
//

#include "header.h"
#define MAX_INT		0xFFFFFFFF
void		perform_single_command(unsigned int count, t_stack *stack, void (*f)(t_stack *))
{
	while (count)
	{
		f(stack);
		count--;
	}
}

void		perform_both_commands(unsigned int count, t_stack *a, t_stack *b, void (*f)(t_stack *, t_stack *))
{
	while (count)
	{
		f(a, b);
		count--;
	}
}

int			both_commands(unsigned int *a, unsigned int *b)
{
	int		res;

	if (*a > *b)
		res = *a - *b;
	else
		res = *b - *a;
	*a = *a - res;
	*b = *b - res;
	return (res);
}

void			count_commands(unsigned int *next, unsigned int *reverse, t_stack *stack, t_node *elem)
{
	unsigned int		i;
	unsigned int		rot;
	t_node				*cur_max;
	t_iter				*iter;

	i = 0;
	rot = 0;
	cur_max = stack->begin;
	iter = new_iter(stack);
	while (i < stack->size)
	{
		//1) найти максимально большое число, после которого можно поставить ноду
		if (iter->cur->val >= elem->val)
		{
			iter->prev(iter);
			rot = i - 1;
			break ;
		}
		if (iter->cur->val > cur_max->val)
		{
			rot = i;
			cur_max = iter->cur;
		}
		iter->next_iter(iter);
		i++;
	}
	*reverse = rot;
	*next = stack->size - *reverse;
	if (*next < *reverse)
		*reverse = 0;
	else
		*next = 0;
	destroy_iter(&iter);
}

unsigned int			count_element(t_stack *a, t_stack *b, t_node *node)
{
	unsigned int		ra_count;
	unsigned int		rra_count;
	unsigned int		rb_count;
	unsigned int		rrb_count;

	ra_count = 0;
	rra_count = 0;
	rb_count = 0;
	rrb_count = 0;
	count_commands(&ra_count, &rra_count, a, node);
	count_commands(&rb_count, &rrb_count, b, node);
	return (ra_count + rra_count + rb_count + rrb_count);
}

/*
 * need to find elem with shortest commands list
 * */

t_node		*find_list(t_stack *a, t_stack *b)
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
		cur = count_element(a, b, iter->cur);
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

void		choose_element(t_stack *a, t_stack *b)
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
	count_commands(&ra_count, &rra_count, a, lst);
	count_commands(&rb_count, &rrb_count, b, lst);

//	perform_both_commands(both_commands(&ra_count, &rb_count), a, b, &rr);
//	perform_both_commands(both_commands(&rra_count, &rrb_count), a, b, &rrr);
	perform_single_command(ra_count, a, &ra);
	perform_single_command(rb_count, b, &rb);
	perform_single_command(rra_count, a, &rra);
	perform_single_command(rrb_count, b, &rrb);
}