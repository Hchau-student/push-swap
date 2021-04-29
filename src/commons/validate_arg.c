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
		return (FALSE);
	if (flag[1] != 'v')
		return (FALSE);
	return (TRUE);
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
	nodes = nodes->prev;
	if (((nums_table[cur_inx % TBL_SZ]) & (1 << (cur_inx % sizeof(int)))) != 0)
	{
		while (size)
		{
			ft_putnbr(nodes->val);
			ft_putstr(" ");
			if (nodes->val == val)
				return (1);
			nodes = nodes->prev;
			size--;
		}
	}
	nums_table[cur_inx % TBL_SZ] |= (1 << (cur_inx % sizeof(int)));
	return (0);
}

int	arg_is_command(char *arg)
{
	int		res;

	res = FALSE;
	res |= (ft_strequ(arg, "sa"));
	res |= (ft_strequ(arg, "sb"));
	res |= (ft_strequ(arg, "ss"));
	res |= (ft_strequ(arg, "pa"));
	res |= (ft_strequ(arg, "pb"));
	res |= (ft_strequ(arg, "ra"));
	res |= (ft_strequ(arg, "rb"));
	res |= (ft_strequ(arg, "rr"));
	res |= (ft_strequ(arg, "rra"));
	res |= (ft_strequ(arg, "rrb"));
	res |= (ft_strequ(arg, "rrr"));
	return (res == 1);
}