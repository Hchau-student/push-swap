//
// Created by Hugor Chau on 3/14/21.
//

#include "header.h"
#define TESTS 3
#define OK 0
#define KO 1

/*
**		NULL check, n <= 1 check
*/

static int 		block_1()
{
	int		n = 0;
	char	**args = NULL;

	if (!validate_cl(n, args))
		return (KO);
	if (!validate_cl(1, args))
		return (KO);
	if (!validate_cl(2, args))
		return (KO);
	return (OK);
}

/*
**		should be valid
*/

static int 		block_2()
{
	if (validate_cl(10, (char* [10]){
			"1", "2", "3", "4", "5", "6", "7", "1", "92", "1"
	}))
		return (KO);
	if (validate_cl(10, (char* [10]){
			"-1", "-2", "-3", "-4", "-5", "-6", "-7", "-1", "-92", "-1"
	}))
		return (KO);
	if (validate_cl(10, (char* [10]){
			"-1", "-2", "-3", "-4", "-5", "-6939389", "-7", "-1", "-92", "-1"
	}))
		return (KO);
	if (validate_cl(10, (char* [10]){
			"-1", "-v", "-3", "-4", "-5", "-6939389", "-7", "-1", "-92", "-1"
	}))
		return (KO);
	return (0);
}

/*
**		should not be valid
*/

static int 		block_3()
{
	if (!validate_cl(10, (char* [10]){
			"1", "2", "3", "4", "5", "6", "7", "ddm", "92", "1"
	}))
		return (KO);
	if (!validate_cl(10, (char* [10]){
			"-1t", "w-2", "-3", "-d4", "-5", "- 6", "-7 ", "!-1", "-92e", "-\n1"
	}))
		return (KO);
	if (!validate_cl(2, (char* [2]){
			"1", "2147483648"
	}))
		return (KO);
	if (!validate_cl(2, (char* [2]){
			"1", "-2147483649"
	}))
		return (KO);
	if (!validate_cl(10, (char* [10]){
			"-1", "-2", "-3", "-4", "-5", "-6", "-7 ", "-1", "-92", "-1"
	}))
		return (KO);
	if (!validate_cl(10, (char* [10]){
			"-1", "-2", "-c", "-4", "-5", "-6939 389", "        -7 ", "-1", "-92", "-1"
	}))
		return (KO);
	return (0);
}

int			validate_cl_test()
{
	int		(*blocks[TESTS])() = {block_1, block_2, block_3};
	int		i;

	i = 0;
	ft_putendl("\033[38;2;200;20;250mvalidate_cl_test");
	while (i < TESTS)
	{
		if (blocks[i]() == KO)
			ft_putendl("\033[38;2;139;20;39m [KO]");
		else
			ft_putendl("\033[38;2;0;200;39m [OK]");
		i++;
	}
	ft_putstr("\033[0m");
	return (0);
}
