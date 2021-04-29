//
// Created by Hugor Chau on 3/9/21.
//

#include "header.h"

int	fill_curr_node(t_node **node, int content)
{
	if (*node == NULL)
	{
		*node = ft_memalloc(sizeof(t_node));
		(*node)->next = (*node);
		(*node)->prev = (*node);
	}
	else
	{
		(*node)->next = ft_memalloc(sizeof(t_node));
		(*node)->next->prev = *node;
		(*node) = (*node)->next;
		(*node)->next = NULL;
	}
	(*node)->val = content;
	(*node)->index = 0;
	return (0);
}

int	end_list(t_stack *stack, t_node *begin, int res)
{
	if (stack->size == 0)
		return (res);
	stack->end->next = begin;
	begin->prev = stack->end;
	stack->begin = begin;
	return (res);
}

int	get_num(t_stack *a, char *arg, int *nums_table, t_node **tmp)
{
	fill_curr_node(&a->end, ft_atoi(arg));
	if (*tmp == NULL)
		*tmp = a->end;
	a->size++;
	if (check_match((int *)nums_table, a->end, a->size))
		return (end_list(a, *tmp, 1));
	return (0);
}

int	fill_nodes(t_stack *a, t_program *program, char **strings, int *nums_table)
{
	static t_node		*tmp = NULL;
	int					i;

	i = 0;
	if (a->size == 0)
		tmp = NULL;
	else if (tmp == NULL)
		tmp = a->end;
	while (strings[i] != NULL)
	{
		if (arg_is_num(strings[i]))
		{
			if (get_num(a, strings[i], nums_table, &tmp))
				return (end_list(a, tmp, 1));
		}
		else if (arg_is_flag(strings[i]))
			program->visualize = 1;
		else
			return (end_list(a, tmp, 1));
		i++;
	}
	return (end_list(a, tmp, 0));
}

int	parse_nums(t_stack *a, t_program *program, int ac, char **av)
{
	int			i;
	int			nums_table[TBL_SZ];
	char		**args;

	i = 1;
	ft_bzero(nums_table, sizeof(int) * TBL_SZ);
	a->end = NULL;
	a->size = 0;
	while (i < ac)
	{
		args = ft_strsplit(av[i], ' ');
		if (fill_nodes(a, program, args, nums_table))
			return (1);
		ft_freematr(&args);
		i++;
	}
	if (a->size == 0)
		return (1);
	return (0);
}
