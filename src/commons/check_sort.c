//
// Created by Hugor Chau on 4/4/21.
//

#include "swap.h"

int	compare_index(t_node *lhs, t_node *rhs)
{
	if (lhs->index == rhs->index - 1)
		return (TRUE);
	return (FALSE);
}

int	compare_greater(t_node *lhs, t_node *rhs)
{
	if (lhs->val < rhs->val)
		return (TRUE);
	return (FALSE);
}

int	sorted(t_stack *a, int (*compare)(t_node *, t_node *))
{
	unsigned int		i;
	t_bool				res;
	t_iter				*iter;

	i = 0;
	iter = new_iter(a);
	res = TRUE;
	while (i < a->size - 1)
	{
		if (compare(iter->cur, iter->cur->next) == FALSE)
			res = FALSE;
		i++;
		iter->next_iter(iter);
	}
	destroy_iter(&iter);
	return (res);
}

void	get_flag(t_program *program, char *string)
{
	if (string[1] == 'v')
		program->visualize = 1;
	if (string[1] == 'k')
		program->kasino = 1;
}
