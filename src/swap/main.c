//
// Created by Hugor Chau on 2/28/21.
//

#include <header.h>

void	error_manager(char *msg)
{
	ft_putstr("\033[38;2;139;20;39m");
	ft_putendl(msg);
	exit(0);
}

int     main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_node		*main_stack;

	if (validate_cl(ac, av))
		error_manager("invalid line");

//	construct_main_list;
//	construct_a_stack;
//	construct_b_stack;

//	parse_cl(ac, av);//должна читать числа из файла или коммандной строки
	parse_nums(&a, ac, av);//в b->elem лежит null, а должна ссылаться на a->elem, но иметь size == 0
	ft_putendl("aaaaa1");
	validate_cl(ac, av);

	return (0);
}
