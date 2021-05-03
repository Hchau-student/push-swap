//
// Created by Hugor Chau on 4/13/21.
//

#include "swap.h"

void	get_from_b(t_stack *a, t_stack *b)
{
	while (b->size != 0)
	{
		choose_element(a, b);
		exec_2(command(PA), a, b);
	}
}
