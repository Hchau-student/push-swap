//
// Created by Hugor Chau on 4/13/21.
//

#include "header.h"

void	get_from_b(t_stack *a, t_stack *b)
{
	t_iter			*iter;
	t_iter			*iter_b;
	unsigned int	i;

	iter = new_iter(a);
	iter_b = new_iter(b);
	while (b->size != 0)
	{
		choose_element(a, b);
		pa(a, b);
	}
}
