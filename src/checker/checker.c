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

int	need_to_exec_2(t_command *command)
{
	if (ft_strequ(command->msg, "ss"))
		return (TRUE);
	if (ft_strequ(command->msg, "pa"))
		return (TRUE);
	if (ft_strequ(command->msg, "pb"))
		return (TRUE);
	if (ft_strequ(command->msg, "rr"))
		return (TRUE);
	if (ft_strequ(command->msg, "rrr"))
		return (TRUE);
	return (FALSE);
}

int	need_to_exec_b(t_command *command)
{
	if (ft_strequ(command->msg, "sb"))
		return (TRUE);
	if (ft_strequ(command->msg, "rb"))
		return (TRUE);
	if (ft_strequ(command->msg, "rrb"))
		return (TRUE);
	return (FALSE);
}

void	exec_all(t_program *program, t_stack *a, t_stack *b)
{
	while (program->commands)
	{
		if (need_to_exec_2(program->commands->content))
			exec_2(*(t_command *)program->commands->content, a, b);
		else if (need_to_exec_b(program->commands->content))
			exec(*(t_command *)program->commands->content, b);
		else
			exec(*(t_command *)program->commands->content, a);
		program->commands = program->commands->next;
	}
}

int     main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	t_program		program;
	unsigned int	main_size;

	init_stack(&a, &next_iter_a, &prev_iter_a);
	init_stack(&b, &next_iter_b, &prev_iter_b);
	program.commands = NULL;
	if (ac <= 1)
		return (0);
	if (parse_nums(&a, &program, ac, av) && parse_commands(ac, av, &program))
		error_manager("Error");

	if (a.size == 0)
		error_manager("ERROR");
	//2) parse commands and put them into list
	//3) exec commands
	//4) check if a sorted
	b.size = 0;
	b.begin = a.end;
	b.end = b.begin;

	main_size = a.size;
	exec_all(&program, &a, &b);
	indexing(&a);
	if ((sorted(&a, &compare_greater) == FALSE) || a.size != main_size)
		ft_putendl("FALSE");
	else
		ft_putendl("TRUE");
	//2) отсортировать список при помощи текущих комманд
	//3)
}
