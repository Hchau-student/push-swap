//
// Created by irka on 27.05.2020.
//
#include "../../includes/z_checker.h"

//все функции должны быть здесь
void		swap(t_stack **stack)
{
	void	*tmp;

	tmp = (*stack)->nums->content;
	(*stack)->nums->content = (*stack)->nums->next->content;
	(*stack)->nums->next->content = tmp;
}

void		rotate(t_stack **stack)
{
	(*stack)->nums = (*stack)->nums->next;
}

void		rrotate(t_stack **stack)
{
	(*stack)->nums = (*stack)->nums->prev;
}

boolean		create_stack(struct s_stack **new)
{
	if (!(*new = (t_stack *)malloc(sizeof(t_stack))))
		return FALSE;
	(*new)->rotate = rotate;
	(*new)->rrotate = rrotate;
	(*new)->swap = swap;
	//привязать функции
}
