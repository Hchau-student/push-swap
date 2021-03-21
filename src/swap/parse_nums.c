//
// Created by Hugor Chau on 3/9/21.
//

#include "header.h"
#define TABLE_SIZE	3571

int				arg_is_num(char *arg)
{
	if (arg[0] == '-' && arg[1] == 'v')
		return (0);
	return (1);
}

int				check_match(int *nums_table, t_node *nodes, t_node *end)
{
	int curr_index;

	curr_index = end->val < 0 ? end->val * -1 : end->val;
	if (((nums_table[curr_index % TABLE_SIZE]) & (1 << (curr_index % 32))) != 0)
	{
		while (nodes != end)
		{
			if (nodes->val == end->val)
				return (1);
			nodes = nodes->next;
		}
	}
	nums_table[curr_index % TABLE_SIZE] |= (1 << (curr_index % 32));
	return (0);
}

int 			fill_curr_node(t_node *node, int content)
{
	node->val = content;
	node->next = ft_memalloc(sizeof(t_node));
	node->next->next = NULL;
	node->next->prev = node;
	return (0);
}

int				fill_nodes(t_node **a, int ac, char **av, unsigned int *actual_size)
{
	t_node		*tmp;
	int			i;
	int			nums_table[TABLE_SIZE];

	i = 1;
	tmp = *a;
	ft_bzero(nums_table, sizeof(int) * TABLE_SIZE);
	while (i < ac)
	{
		if (arg_is_num(av[i]))
		{
			fill_curr_node(tmp, ft_atoi(av[i]));
			if (check_match((int *)nums_table, *a, tmp))
				return (1);
			tmp = tmp->next;
		}
		else
			*actual_size = *actual_size - 1;
		i++;
	}
	if (*actual_size == 0)
		return (1);
	tmp = tmp->prev;
	free(tmp->next);
	tmp->next = *a;
	(*a)->prev = tmp;
	return (0);
}

int 		parse_nums(t_stack *a, int ac, char **av)
{
	a->begin = ft_memalloc(sizeof(t_node));
	a->size = ac - 1;
	return (fill_nodes(&a->begin, ac, av, &a->size));
}
