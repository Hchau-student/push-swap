#include "header.h"

int	arg_is_num(char *s)
{
	char		*check;

	check = s;
	if (*check == '-')
	{
		if (!ft_isdigit(*(check + 1)))
			return (0);
		check++;
	}
	while (*check)
	{
		if (!ft_isdigit(*check))
			return (0);
		check++;
	}
	if (ft_atoi(s) >= 0 && *s == '-')
		return (0);
	if (ft_atoi(s) < 0 && *s != '-')
		return (0);
	return (1);
}

int	arg_is_flag(char *flag)
{
	if (*flag != '-')
		return (1);
	if (flag[1] != 'v')
		return (1);
	if (flag[2] != '\0' || !(ft_is_whitespace(flag[2])))
		return (1);
	return (0);
}

int	check_match(int *nums_table, t_node *nodes, int size)
{
	int		cur_inx;
	int		val;

	if (size == 0 || nodes == NULL)
		return (0);
	val = nodes->val;
	if (nodes->val < 0)
		cur_inx = -1;
	else
		cur_inx = nodes->val;
	nodes = nodes->next;
	if (((nums_table[cur_inx % TBL_SZ]) & (1 << (cur_inx % sizeof(int)))) != 0)
	{
		while (size)
		{
			ft_putnbr(nodes->val);
			ft_putstr(" ");
			if (nodes->val == val)
				return (1);
			nodes = nodes->next;
			size--;
		}
	}
	nums_table[cur_inx % TBL_SZ] |= (1 << (cur_inx % sizeof(int)));
	return (0);
}
