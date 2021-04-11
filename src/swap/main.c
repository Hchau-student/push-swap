//
// Created by Hugor Chau on 2/28/21.
//

#include <header.h>

void	error_manager(char *msg)
{
	ft_putstr("\033[38;2;139;20;39m");
	ft_putendl(msg);
	exit(0);
}

static void init_stack(t_stack *init, t_node *(*next)(t_stack *))
{
	init->begin = NULL;
	init->size = 0;
	init->next = next;
}

void	check_res(t_stack *a)
{
	unsigned int		i;

	i = 0;
	ft_putendl("yes");
	while (i < a->size)
	{
		ft_putnbr(a->cur->val);
		ft_putstr(" ");
		a->next(a);
		i++;
	}
}

int     main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_program	program;

	init_stack(&a, &next_a);
	init_stack(&b, &next_b);

	if (parse_nums(&a, &program, ac, av))
		error_manager("nums are invalid");//в b->elem лежит null, а должна ссылаться на a->elem, но иметь size == 0
	b.size = 0;
	b.begin = a.end;
	b.end = b.begin;
	b.cur = b.begin;
	main_cycle(&a, &b);
	check_res(&a);
	return (0);
}
