//
// Created by Hugor Chau on 4/26/21.
//

#include "checker.h"

static void	init_stack(t_stack *init, t_node *(*next_iter)(t_iter *),
						  t_node *(*prev_iter)(t_iter *))
{
	init->begin = NULL;
	init->size = 0;
	init->next_iter = next_iter;
	init->prev_iter = prev_iter;
}

int     main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_program	program;

	init_stack(&a, &next_iter_a, &prev_iter_a);
	init_stack(&b, &next_iter_b, &prev_iter_b);
	if (parse_nums(&a, &program, ac, av) && parse_commands(ac, av, &program))
		error_manager("nums are invalid");

	//2) parse commands and put them into list
	//3) exec commands
	//4) check if a sorted
	b.size = 0;
	b.begin = a.end;
	b.end = b.begin;

	//2) отсортировать список при помощи текущих комманд
	//3)
}
