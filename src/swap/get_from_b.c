//
// Created by Hugor Chau on 4/13/21.
//

#include "header.h"

void		get_from_b(t_stack *a, t_stack *b)
{
	t_iter					*iter;
	t_iter					*iter_b;
	unsigned int		i;

	iter = new_iter(a);
	iter_b = new_iter(b);
	while (b->size != 0)
	{
		iter = new_iter(a);
		iter_b = new_iter(b);
		i = 0;
		ft_putstr("a: ");
//		ft_putnbr(a->size);
		iter = new_iter(a);
//		ft_putnbr(a->begin->val);
		while (i < a->size)// * 2)
		{
			if (i == a->size)
			{
				ft_putstr(": ");
				ft_putnbr(a->end->val);
				ft_putstr(": ");
//				ft_putnbr(a->begin->val);
				iter = new_iter(a);
			}
			ft_putnbr(iter->cur->val);
			ft_putstr(" ");
			iter->next_iter(iter);
			i++;
		}
		ft_putendl("");
		ft_putstr("b: ");
//		ft_putnbr(b->begin->val);
		i = 0;
		while (i < b->size)// * 2)
		{
			if (i == b->size)
			{
				ft_putstr(": ");
//				ft_putnbr(b->end->val);
//				ft_putstr(": ");
				iter_b = new_iter(b);
			}
			ft_putnbr(iter_b->cur->val);
			ft_putstr(" ");
			iter_b->next_iter(iter_b);
			i++;
		}
		ft_putendl("");
		choose_element(a, b);
		pa(a, b);
//		choose element in stack B for moving to stack A
//		move stack A and stack B to prepare them for pa (push a) with chosen element
//      perform pa (push a) command
	}
}