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
	t_list	*tmp;

	tmp = program->commands;
	while (tmp)
	{
		if (need_to_exec_2(tmp->content))
			exec_2(*(t_command *)tmp->content, a, b);
		else if (need_to_exec_b(tmp->content))
			exec(*(t_command *)tmp->content, b);
		else
			exec(*(t_command *)tmp->content, a);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	t_program		program;

	init_stack(&a, &next_iter_a, &prev_iter_a);
	init_stack(&b, &next_iter_b, &prev_iter_b);
	program.commands = NULL;
	if (parse_nums(&a, &program, ac, av))
		error_manager("Error");
	parse_commands(ac, av, &program);
	if (a.size == 0)
		error_manager("ERROR");
	b.size = 0;
	b.begin = a.end;
	b.end = b.begin;
	exec_all(&program, &a, &b);
	if ((sorted(&a, &compare_greater) == FALSE) || b.size != 0)
	{
		if (program.kasino)
			system("open https://www.youtube.com/watch?v=nThKRtq5D3w");
		ft_putendl("KO");
	}
	else
		ft_putendl("OK");
}
