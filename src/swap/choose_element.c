//
// Created by Hugor Chau on 4/11/21.
//

#include "header.h"

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

	i = 0;
	while (i < stack->size && stack->cur->val > elem->val)
	{
		stack->next(stack);
		i++;
		*reverse = *reverse + 1;
	}
	while (i < stack->size)
	{
		stack->next(stack);
		*next = *next + 1;
		i++;
	}
	if (*next < *reverse)
		*reverse = 0;
	else
		*next = 0;
}


/*
 * need to find elem with shortest commands list
 * */
int			count_element(t_stack *a, t_stack *b)
{
	return (0);
}

void		choose_element(t_stack *a, t_stack *b)
{
	unsigned int		ra_count;
	unsigned int		rra_count;
	unsigned int		rb_count;
	unsigned int		rrb_count;

	ra_count = 0;
	rra_count = 0;
	rb_count = 0;
	rrb_count = 0;
	count_commands(&ra_count, &rra_count, a, b->begin);
	count_commands(&rb_count, &rrb_count, b, b->begin);

	perform_both_commands(both_commands(&ra_count, &rb_count), a, b, &rr);
	perform_both_commands(both_commands(&rra_count, &rrb_count), a, b, &rrr);
	perform_single_command(ra_count, a, &ra);
	perform_single_command(rb_count, b, &rb);
	perform_single_command(rra_count, a, &rra);
	perform_single_command(rrb_count, b, &rrb);
}