#include "header.h"

void	get_a_sorted(t_stack *a)
{
	t_command		rotate_a;

	if (a->begin->index <= a->size / 2)
		rotate_a = command(RRA);
	else
		rotate_a = command(RA);
	while (a->begin->index != 0)
		exec(rotate_a, a);
}

void	main_cycle(t_stack *a, t_stack *b)
{
	indexing(a);
	prepare_a(a, b);
	get_from_b(a, b);
	get_a_sorted(a);
}
