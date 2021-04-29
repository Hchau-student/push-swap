//
// Created by Hugor Chau on 4/29/21.
//
#include "checker.h"

int	fill_commands(t_program *program, char **strings)
{
	static t_node		*tmp = NULL;
	int					i;

	i = 0;
	while (strings[i] != NULL)
	{
		if (arg_is_num(strings[i]))
		{

		}
		else if (arg_is_flag(strings[i]))
			program->visualize = 1;
		else if (arg_is_command(strings[i]))
			;//put command in list
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
	while (i < ac)
	{
		args = ft_strsplit(av[i], ' ');
		if (fill_commands(program, args))
			return (-1);
		i++;
	}
	return (0);
}
