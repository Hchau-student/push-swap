//
// Created by Hugor Chau on 4/13/21.
//

#include "header.h"

void		get_from_b(t_stack *a, t_stack *b)
{
	t_iter					*iter;
	unsigned int		i;

	iter = new_iter(a);
	while (b->size != 0)
	{
		i = 0;
		while (i < a->size)
		{
			ft_putnbr(iter->cur->val);
			ft_putstr(" ");
			iter->next_iter(iter);
			i++;
		}
		choose_element(a, b);
		pa(a, b);
//		choose element in stack B for moving to stack A
//		move stack A and stack B to prepare them for pa (push a) with chosen element
//      perform pa (push a) command
	}
}