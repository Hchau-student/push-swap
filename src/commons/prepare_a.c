#include "header.h"

void	sa_test(t_node *a, t_node *a_next)
{
	t_val		tmp;

	tmp = a->val;
	a->val = a_next->val;
	a_next->val = tmp;
}

t_bool	needs_to_swap(t_stack *a)
{
	unsigned int	first_res;
	unsigned int	second_res;

	if (a->size <= 1)
		return (FALSE);
	if (a->begin == NULL || a->begin->next == NULL)
		return (FALSE);
	markup_greater(a);
	first_res = find_max_len(a);
	sa_test(a->begin, a->begin->next);
	markup_greater(a);
	second_res = find_max_len(a);
	sa_test(a->begin, a->begin->next);
	markup_greater(a);
	if (first_res < second_res)
		return (TRUE);
	return (FALSE);
}

int	has_false(t_stack *a)
{
	unsigned int	i;
	t_iter			*iter;
	t_bool			res;

	i = 0;
	res = FALSE;
	iter = new_iter(a);
	while (i < a->size)
	{
		if (iter->cur->markup_greater == FALSE)
			res = TRUE;
		iter->next_iter(iter);
		i++;
	}
	destroy_iter(&iter);
	return (res);
}

void	prepare_a(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
	{
		if (a->begin->index > a->begin->next->index)
			exec(command(SA), a);
		return ;
	}
	while (has_false(a) && (sorted(a, &compare_greater) == FALSE))
	{
		markup_greater(a);
		find_markup_head(a);
		if (needs_to_swap(a))
		{
			exec(command(SA), a);
			markup_greater(a);
		}
		else if (a->begin->markup_greater == FALSE)
			exec_2(command(PB), a, b);
		else if (a->begin->val > a->begin->next->val)
			exec(command(RA), a);
		else
			exec(command(RRA), a);
	}
}
