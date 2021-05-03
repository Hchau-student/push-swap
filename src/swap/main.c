#include <swap.h>

static void	init_stack(t_stack *init, t_node *(*next_iter)(t_iter *),
						t_node *(*prev_iter)(t_iter *))
{
	init->begin = NULL;
	init->size = 0;
	init->next_iter = next_iter;
	init->prev_iter = prev_iter;
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_program	program;

	if (ac <= 1)
		return (0);
	init_stack(&a, &next_iter_a, &prev_iter_a);
	init_stack(&b, &next_iter_b, &prev_iter_b);
	if (parse_nums(&a, &program, ac, av))
		error_manager("nums are invalid");
	if (a.size == 0)
		error_manager("ERROR");
	b.size = 0;
	b.begin = a.end;
	b.end = b.begin;
	main_cycle(&a, &b);
	return (0);
}
