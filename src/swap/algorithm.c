//
// Created by Hugor Chau on 3/28/21.
//

#include "header.h"

//t_bool			recount_stack(t_stack *stack)
//{
//	unsigned int		i;
//	unsigned int		max_len;
//	unsigned int		curr_len;
//	t_node				*tmp;
//	t_bool				res;
//
//	i = 0;
//	res = TRUE;
//	curr_len = 0;
//	max_len = 0;
//	tmp = stack->begin;
//	while (i < stack->size)
//	{
//		if (stack->cur->markup_greater == TRUE)
//			curr_len++;
//		else
//		{
//			res = FALSE;
//			tmp = stack->cur;
//			curr_len = 0;
//		}
//		if (curr_len > max_len)
//		{
//			stack->max_len_greater = tmp;
//			max_len = curr_len;
//		}
//		if (curr_len == max_len && stack->max_len_greater->index > tmp->index)
//			stack->max_len_greater = tmp;
//		stack->next(stack);
//		i++;
//	}
//	stack->cur = stack->begin;
//	return res;
//}

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
	t_bool		res = FALSE;

	while (i < a->size)
	{
		if (a->cur->markup_greater == FALSE)
			res = TRUE;
		a->next(a);
		i++;
	}
	return (res);
}

void		main_cycle(t_stack *a, t_stack *b)
{
	unsigned int			main_size;

	main_size = a->size;
	indexing(a);
	unsigned int		i;
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
		{
			ft_putendl(a->begin->markup_greater == FALSE ? "FALSE" : "TRUE");
			pb(a, b);
		}
		else
		{
			ra(a);
		}
	}
	while (b->size != 0)
	{
		i = 0;
		ft_putendl("yes1");
		while (i < a->size)
		{
			ft_putnbr(a->cur->val);
			ft_putstr(" ");
			a->next(a);
			i++;
		}
		choose_element(a, b);
//		choose element in stack B for moving to stack A
//		move stack A and stack B to prepare them for pa (push a) with chosen element
//      perform pa (push a) command
	}
}