//
// Created by Hugor Chau on 3/20/21.
//

#include "header.h"
#define TESTS 3
#define OK 0
#define KO 1

/*
**		simple: 10 nums
*/

#define AC0 10
#define AV0 (char* [AC0]) { \
                    "a.out\0", \
                    "10\0", \
                    "20\0", \
                    "30\0", \
                    "40\0", \
                    "50\0", \
                    "60\0", \
                    "70\0", \
                    "80\0", \
					"90\0"  \
					}

#define AC1 11
#define AV1 (char* [AC1]) {"a.out", "-v", "-v", "-v", "-v", "-v", "-v", "-v", "-v", "-v", "1"}

#define AC2 4
#define AV2 (char* [AC2]) {"a.out", "-10", "2147483647", "0"}

/*
**		invalid tests_src
*/

#define N_AC0 1
#define N_AV0 (char* [N_AC0]) {"a.out"}

#define N_AC1 10
#define N_AV1 (char* [N_AC1])  {"a.out", "-1", "341242", "3413432", "43242332", "5", "41165", "2861", "445", "-1"}

#define N_AC2 10
#define N_AV2 (char* [N_AC2])  {"a.out", "-v", "341242", "3413432", "3413432", "5", "41165", "2861", "445", "-1"}

static int		test_content(t_node	*a, char **expected, unsigned int a_size)
{
	int		s = a_size;

	ft_putstr("\033[38;2;0;200;39msize == ");
	ft_putnbr(s);
	ft_putstr("\033[38;2;200;20;250m");
	ft_putstr(" ");
	a = a->prev;
	for (int i = 0; i < s; i++)
	{
		ft_putnbr(a->val);
		ft_putstr(" ");
		if (expected[i + 1][0] == '-' && expected[i + 1][1] == 'v')
			continue ;
		if (a->val != ft_atoi(expected[i + 1]))
			return (KO);
		a = a->prev;
	}
	return (OK);
}

static int 		block_1(int num)
{
	t_stack		a;

	if (num == 0) {
		if (parse_nums(&a, AC0, AV0))
			return (KO);
		return (test_content(a.begin, AV0, a.size));
	}
	if (num == 1) {
		if (parse_nums(&a, AC1, AV1))
			return (OK);
		return (test_content(a.begin, AV1, a.size));
	}
	if (num == 2) {
		if (parse_nums(&a, AC2, AV2))
			return (KO);
		return (test_content(a.begin, AV2, a.size));
	}
	return (OK);
}

static int 		block_2(int num)
{
	t_stack		a;
	int			res = 0;

	if (num == 0)
	{
		res = parse_nums(&a, N_AC0, AV0);
		test_content(a.begin, N_AV0, a.size);
		return res == 0 ? OK : KO;
	}
	if (num == 1)
	{
		res = parse_nums(&a, N_AC1, N_AV1);
		test_content(a.begin, N_AV1, a.size);
		return res == 0 ? OK : KO;
	}
	if (num == 2)
	{
		res = parse_nums(&a, N_AC2, N_AV2);
		test_content(a.begin, N_AV2, a.size);
		return res == 0 ? OK : KO;
	}
	return (OK);
}

int			parse_nums_test()
{
	int		(*blocks[2])(int) = {block_1, block_2};
	int		i;

	i = 0;
	ft_putendl("\033[38;2;200;20;250mparse_num_test");
	ft_putendl("\033[38;2;200;20;250mvalid:");
	while (i < TESTS)
	{
		if (blocks[0](i) == KO)
			ft_putendl("\033[38;2;139;20;39m [KO]");
		else
			ft_putendl("\033[38;2;0;200;39m [OK]");
		i++;
	}
	i = 0;
	ft_putendl("\033[38;2;200;20;250minvalid:");
	while (i < TESTS)
	{
		if (blocks[1](i) == OK)//this tests_src shouldn't be OK
			ft_putendl("\033[38;2;139;20;39m [KO]");
		else
			ft_putendl("\033[38;2;0;200;39m [OK]");
		i++;
	}
	ft_putstr("\033[0m");
	return (0);
}