#include "header.h"

void	get_a_sorted(t_stack *a)
{
	void		(*rotate_a)(t_stack *);

	if (a->begin->index <= a->size / 2)
		rotate_a = &rra;
	else
		rotate_a = &ra;
	while (a->begin->index != 0)
		rotate_a(a);
}

void	main_cycle(t_stack *a, t_stack *b)
{
	unsigned int			main_size;

	main_size = a->size;
	indexing(a);
	prepare_a(a, b);
	get_from_b(a, b);
	get_a_sorted(a);
}
