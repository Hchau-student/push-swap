//
// Created by Hugor Chau on 3/14/21.
//

#include "header.h"

static int			check_num(char *s)
{
	char		*check;

	check = s;
	if (*check == '-')
	{
		if (!ft_isdigit(*(check + 1)))
			return (1);
		check++;
	}
	while (*check)
	{
		if (!ft_isdigit(*check))
			return (1);
		check++;
	}
	if (ft_atoi(s) >= 0 && *s == '-')
		return (1);
	if (ft_atoi(s) < 0 && *s != '-')
		return (1);
	return (0);
}

static int			check_flag(char *flag)
{
	if (*flag != '-')
		return (1);
	if (flag[1] != 'v')
		return (1);
	if (flag[2] != '\0')
		return (1);
	return (0);
}

int			validate_cl(int ac, char **av)
{
	int			i;

	if (ac <= 1 || av == NULL)
		return (1);
	i = 1;
	while (i < ac)
	{
		if (av[i] == NULL)
			return (1);
		if (check_flag(av[i]) && check_num(av[i]))
			return (1);
		i++;
	}
	return (0);
}
