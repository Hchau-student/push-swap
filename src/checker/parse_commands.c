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

int	parse_commands(int ac, char **av, t_program *program)
{
	program->commands = NULL;
    char *line;

    while (get_next_line(2, &line))
    {
        if (arg_is_command(line))
            new_command(&program->commands, line);//put command in list
        else
            error_manager("command is invalid");
    }
	return (0);
}
