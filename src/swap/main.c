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

static void init_stack(t_stack *init)
{
	init->begin = NULL;
	init->size = 0;
}

int     main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_program	program;

	init_stack(&a);
	init_stack(&b);

	if (parse_nums(&a, &program, ac, av))
		error_manager("nums are invalid");//в b->elem лежит null, а должна ссылаться на a->elem, но иметь size == 0
	ft_putendl("aaaaa1");

	return (0);
}
