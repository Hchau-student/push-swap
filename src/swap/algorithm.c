#include "header.h"

void	main_cycle(t_stack *a, t_stack *b)
{
	unsigned int			main_size;

	main_size = a->size;
	indexing(a);
	prepare_a(a, b);
	get_from_b(a, b);
}
