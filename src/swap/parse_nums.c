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
	if (((nums_table[curr_index % TABLE_SIZE]) & (1 << (curr_index % sizeof(int)))) != 0)
	{
		while (nodes != end)
		{
			if (nodes->val == end->val)
				return (1);
			nodes = nodes->next;
		}
	}
	nums_table[curr_index % TABLE_SIZE] |= (1 << (curr_index % sizeof(int)));
	return (0);
}

int 			fill_curr_node(t_node *node, int content)
{
	//if (*node == NULL)
	//{
	//		*node = ft_memalloc(sizeof(t_node));
	//		*node->val = content;
	//		*node->next = *node;
	//
	//}
	node->val = content;
	node->prev = ft_memalloc(sizeof(t_node));
	node->prev->next = node;
	node->prev->prev = NULL;
	return (0);
}

int				fill_nodes(t_node *a, char **strings, unsigned int *actual_size, int *nums_table)
{
	static t_node		*tmp;
	int			i;

	i = 0;
	tmp = a;
	while (strings[i] != NULL)
	{
		if (arg_is_num(strings[i]))
		{
			fill_curr_node(tmp, ft_atoi(strings[i]));
			if (check_match((int *)nums_table, a, tmp))
				return (1);
			tmp = tmp->prev;
			*actual_size = *actual_size + 1;
		}
		i++;
	}
	if (*actual_size == 0)
		return (0);
	tmp = tmp->next;
	free(tmp->prev);
	tmp->prev = a;
	(a)->next = tmp;
	return (0);
}

int 		parse_nums(t_stack *a, int ac, char **av)
{
	int			i;
	int			nums_table[TABLE_SIZE];

	i = 1;
	ft_bzero(nums_table, sizeof(int) * TABLE_SIZE);

	a->begin = ft_memalloc(sizeof(t_node));

	a->begin->next = a->begin;
	a->begin->prev = a->begin;

	a->size = 0;
	while (i < ac)
	{
		if (fill_nodes(a->begin->prev, ft_strsplit(av[i], ' '), &a->size, nums_table))
			return (1);//to the end of the list
		i++;
	}
	if (a->size == 0)
		return (1);
	return (0);
}