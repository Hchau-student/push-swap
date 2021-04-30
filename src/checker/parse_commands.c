//
// Created by Hugor Chau on 4/29/21.
//
#include "checker.h"

void new_command(t_list **commands, char *str)
{
	t_command	*command_res;
	t_list		*tmp;

	command_res = ft_memalloc(sizeof (t_command));
	*command_res = command(get_command(str));
	if (*commands == NULL)
	{
		*commands = ft_lstnew(command_res, sizeof(t_command));
		(*commands)->next = NULL;
	}
	else
	{
		tmp = *commands;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(command_res, sizeof(t_command));
		tmp->next->next = NULL;
	}
}

int	fill_commands(t_program *program, char **strings)
{
	int					i;

	i = 0;
	while (strings[i] != NULL)
	{
		if (arg_is_num(strings[i]))
			;
		else if (arg_is_flag(strings[i]))
			program->visualize = 1;
		else if (arg_is_command(strings[i]))
			new_command(&program->commands, strings[i]);//put command in list
		else
			return (-1);
		i++;
	}
	return (0);
}

int	parse_commands(int ac, char **av, t_program *program)
{
	int			i;
	char		**args;

	i = 1;
	program->commands = NULL;
	while (i < ac)
	{
		args = ft_strsplit(av[i], ' ');
		if (fill_commands(program, args))
			return (-1);
		i++;
	}
	return (0);
}
