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

static t_node	*next_a(t_stack *a)
{
	a->cur = a->cur->next;
	return (a->cur);
}

static t_node	*next_b(t_stack *b)
{
	b->cur = b->cur->prev;
	return (b->cur);
}

static void init_stack(t_stack *init, t_node *(*next)(t_stack *))
{
	init->begin = NULL;
	init->size = 0;
	init->next = next;
}

int     main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_program	program;

	init_stack(&a, next_a);
	init_stack(&b, next_b);

	if (parse_nums(&a, &program, ac, av))
		error_manager("nums are invalid");//в b->elem лежит null, а должна ссылаться на a->elem, но иметь size == 0
	b.size = 0;
	b.begin = a.end;
	b.end = b.begin;
	b.cur = b.begin;
	return (0);
}
