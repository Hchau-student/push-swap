//
// Created by Hugor Chau on 4/13/21.
//
#include "header.h"

void			sa_test(t_node *a, t_node *a_next)
{
	t_val		tmp;

	tmp = a->val;
	a->val = a_next->val;
	a_next->val = tmp;
}

t_bool		needs_to_swap(t_stack *a)
{
	unsigned int	first_res;
	unsigned int	second_res;

	if (a->size <= 1)
		return FALSE;
	if (a->begin == NULL || a->begin->next == NULL)//чекнуть все ошибки
		return FALSE;
	markup_greater(a);
//	find_markup_head(a);
	first_res = find_max_len(a);
	sa_test(a->begin, a->begin->next);
	markup_greater(a);
//	find_markup_head(a);
	second_res = find_max_len(a);
	sa_test(a->begin, a->begin->next);
	markup_greater(a);
	if (first_res < second_res)
		return (TRUE);
	return (FALSE);
}

int			has_false(t_stack *a) {
	unsigned int i = 0;
	t_iter		*iter;
	t_bool		res = FALSE;

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

void		prepare_a(t_stack *a, t_stack *b)
{
	while (has_false(a))
	{
		markup_greater(a);
		find_markup_head(a);
		if (needs_to_swap(a))
		{
			sa(a);
			markup_greater(a);
		}
		else if (a->begin->markup_greater == FALSE)
			pb(a, b);
		else
			ra(a);
	}
}
