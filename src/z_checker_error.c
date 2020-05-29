//
// Created by irka on 02.05.2020.
//
#include "../includes/z_checker.h"

void	checker_exit(char *reason)
{
	ft_putendl(reason);
	exit(0);
}

t_swap_number	*check_valid(char *check_num, size_t *i)
{
	t_swap_number 	*res;
	char 			success;

	success = TRUE;
	return (res = str_to_num(check_num, &success, i));
}

t_twlist	*check_num_arr(char **av, int ac)
{
	int 		i;
	t_twlist	*res;
	size_t 		index = 0;

	res = NULL;
	i = 1;
	while (i < ac)
	{
		index = 0;
		if (ft_strlen(av[i]) == 0)
		{
			i++;
			continue ;
		}
		while (index == 0 || index < ft_strlen(av[i]))
		{
			t_swap_number *p = check_valid(av[i], &index);
			if (p != NULL)
			{
				ft_twlstend(&res, ft_twlstnew(p, sizeof(t_swap_number)));
				if (res) {
					if (p != NULL)
						p->print(p);
				}
				ft_putendl(OK);
			}
		}
		i++;
	}
	return (res);
}