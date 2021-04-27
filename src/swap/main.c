#include <header.h>

static void	init_stack(t_stack *init, t_node *(*next_iter)(t_iter *),
						t_node *(*prev_iter)(t_iter *))
{
	init->begin = NULL;
	init->size = 0;
	init->next_iter = next_iter;
	init->prev_iter = prev_iter;
}

void	check_res(t_stack *a)
{
	unsigned int		i;
	t_iter				*iter;

	i = 0;
	iter = new_iter(a);
	while (i < a->size)
	{
		ft_putnbr(iter->cur->val);
		ft_putstr(" ");
		iter->next_iter(iter);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_program	program;

	init_stack(&a, &next_iter_a, &prev_iter_a);
	init_stack(&b, &next_iter_b, &prev_iter_b);
	if (parse_nums(&a, &program, ac, av))
		error_manager("nums are invalid");
	b.size = 0;
	b.begin = a.end;
	b.end = b.begin;
	main_cycle(&a, &b);
	check_res(&a);
	return (0);
}
