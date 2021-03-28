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
                    "10 9 8 7 6 5 4 3 2 1 0", \
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
#define AV1 (char* [AC1]) {"a.out", "", "-v", "-v", "-v", "-v", "-v", "-v", "-v", "-v", "1"}

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

static t_node	*next_a(t_stack *a)
{
	a->cur = a->cur->next;
	return (a->cur);
}

static t_node	*next_b(t_stack *b)
{
	b->cur = b->cur->prev;
	return (b->cur);
}

static void init_stack(t_stack *init, t_node *(*next)(t_stack *))
{
	init->begin = NULL;
	init->size = 0;
	init->next = next;
}

static int		test_content(t_stack *a, char **expected, unsigned int a_size)
{
	int		s = a_size;

	ft_putstr("\033[38;2;0;200;39msize == ");
	ft_putnbr(s);
	ft_putstr("\033[38;2;200;20;250m");
	ft_putstr(" ");
	if (a->begin == NULL && a_size == 0)
		return (OK);
//	a = a->prev;
	for (int i = 0; i < s; i++)
	{
		ft_putnbr(a->cur->val);
		ft_putstr(" ");
		if (expected[i + 1][0] == '-' && expected[i + 1][1] == 'v')
			continue ;
//		if (a->val != ft_atoi(expected[i + 1]))
//			return (KO);
		a->next(a);
	}
	return (OK);
}

static int 		block_1(int num)
{
	t_stack		a;
	t_stack		b;
	t_program program;

	init_stack(&a, next_a);
	init_stack(&b, next_b);
	if (num == 0) {
		if (parse_nums(&a, &program, AC0, AV0))
			return (KO);
		b.size = 0;
		b.begin = a.end;
		b.end = b.begin;
		b.cur = b.begin;
//		pb(&a, &b);
//		pb(&a, &b);
//		pb(&a, &b);
//		pb(&a, &b);
//		pb(&a, &b);
//		pb(&a, &b);
//		pb(&a, &b);
//		pb(&a, &b);
//		pb(&a, &b);
//		pb(&a, &b);
//		pb(&a, &b);
//		pb(&a, &b);
//		rb(&b);
//		rb(&b);
//		rrb(&b);
//		rrb(&b);
//		pa(&a, &b);
//		pa(&a, &b);
//		pa(&a, &b);
//		pa(&a, &b);
//		pa(&a, &b);
//		pa(&a, &b);
//		pa(&a, &b);
//		pa(&a, &b);
//		pa(&a, &b);
//		pa(&a, &b);
//		pa(&a, &b);
//		pa(&a, &b);

		(test_content(&a, AV0, a.size));
		return (test_content(&b, AV0, b.size));
	}
	if (num == 1) {
		if (parse_nums(&a, &program, AC1, AV1))
			return (KO);
		return (test_content(&a, AV1, a.size));
	}
	if (num == 2) {
		if (parse_nums(&a, &program, AC2, AV2))
			return (KO);
		return (test_content(&a, AV2, a.size));
	}
	return (OK);
}

static int 		block_2(int num)
{
	t_stack		a;
	t_stack		b;
	int			res = 0;
	t_program program;

	init_stack(&a, next_a);
	init_stack(&b, next_b);
	if (num == 0)
	{
		res = parse_nums(&a, &program, N_AC0, AV0);
		test_content(&a, N_AV0, a.size);
		return res == 0 ? OK : KO;
	}
	if (num == 1)
	{
		res = parse_nums(&a, &program, N_AC1, N_AV1);
		test_content(&a, N_AV1, a.size);
		ft_putstr(res == 0 ? "KO" : "OK");
		return res == 0 ? OK : KO;
	}
	if (num == 2)
	{
		res = parse_nums(&a, &program, N_AC2, N_AV2);
		test_content(&a, N_AV2, a.size);
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