//
// Created by irka on 02.05.2020.
//
#include "../../includes/z_checker.h"

void	check_nums(t_stack **res)
{
	int 	i = 0;
	t_swap_number	*a1;
	t_swap_number	*b;
	t_stack			*tmp;
	t_stack			*a;
	tmp = *res;
	a = *res;

//	while (i < a->list_size - 1)
//	{
		a1 = a->nums->content;
//		a1->print(a1);
		b = a->nums->next->content;
//		b->print(b);
		if (a1->more(a1, b))
		{
			a->swap(&a);
//			a->nums->content = b;
//			a->nums->next->content = a1;
			i = 0;
			a = tmp;
		}
		else
		{
			i++;
//			a->nums = a->nums->next;
		}
//	}
	a = tmp;
	*res = a;
}

void	fill_stack(t_stack **a, char **av, int ac)
{
	int 		nums_count;
	t_twlist	*nums;
	t_twlist	*tmp;
	t_swap		*core;

	nums_count = 0;
	create_stack(a);
	if ((nums = check_num_arr(av, ac)) == NULL)
		checker_exit(TOO_FEW_ARG);
	(*a)->nums = nums;
	create_core(&core);
	core->a = *a;
	create_stack(&core->b);
	while (nums)
	{
		tmp = nums;
		nums = nums->prev;
		nums_count++;
	}
	(*a)->list_size = nums_count;
//	return;
	if (tmp != NULL)		//зацикливаю список
	{
		tmp->prev = (*a)->nums;
		(*a)->nums->next = tmp;
		(*a)->nums = tmp;	//откатываюсь на 1 лист (сейчас нахожусь на последнем из-за порядка добавления)
	}
	//проверка:
//	core->push_b(core);
//	core->push_b(core);
//	core->push_b(core);
//	core->push_a(core);
//	core->push_a(core);
//	core->push_a(core);
//	core->push_a(core);
//	check_nums(&core->a);

//	nums_count = core->b->list_size;
//	while (core->b->nums && nums_count)
//	{
//		t_swap_number *t;
//		t = core->b->nums->content;
//		t->print(t);
//		core->b->nums = core->b->nums->next;
//		nums_count--;
//	}
	nums_count = core->a->list_size;
	while (core->a->nums && nums_count)
	{
		t_swap_number *t;
		t = core->a->nums->content;
		t->print(t);
		core->a->nums = core->a->nums->next;
		nums_count--;
	}
//	while (core->a->nums && nums_count)
//	{
//		t_swap_number *t;
//		t = core->a->nums->content;
//		t->print(t);
//		core->a->nums = core->a->nums->next;
//		nums_count--;
//	}
//	nums_count = core->a->list_size;
//	while (core->a->nums && nums_count)
//	{
//		t_swap_number *t;
//		t = core->a->nums->content;
//		t->print(t);
//		core->a->nums = core->a->nums->next;
//		nums_count--;
//	}
}

int		main(int ac, char ** av)
{
	t_stack		*a;

	/*    должен быть массив интов + чекер    */
	if (ac < 2)
		checker_exit(TOO_FEW_ARG);
	else
	{
		fill_stack(&a, av, ac);
	}
	//проверить и записать в список пулл первых аргументов, если
	//они даны в командной строке

	//

//	if ()
	//проверить и записать в список пулл сл
	return (0);
}
