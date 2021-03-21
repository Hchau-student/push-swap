//
// Created by Hugor Chau on 3/9/21.
//

#include "header.h"

t_node		*next()
{
	return NULL;
}

void		init_stack(t_stack *init)
{
	init->begin = NULL;
	init->size = 0;
	ft_putendl("In init_queue");
	init->next = next;
}
