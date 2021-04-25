//
// Created by Hugor Chau on 3/27/21.
//

/*
 * rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.
*/

#include "header.h"

static void		rra_void(t_stack *rotate)
{
    t_node		*tmp;
    t_node		*new_end;

    if (rotate->size <= 1)
        return;
    if (rotate->begin == NULL || rotate->end == NULL)
        return;
    tmp = rotate->end;
    new_end = tmp->prev;
    rotate->end = new_end;
    new_end->next = tmp->next;
    new_end->next->prev = new_end;
    tmp->next = rotate->begin;
    tmp->prev = rotate->begin->prev;
    rotate->begin->prev = tmp;
    tmp->prev->next = tmp;
    rotate->begin = tmp;
}

void		rrb_void(t_stack *rotate)
{
    t_node		*tmp;
    t_node		*new_end;

    if (rotate->size <= 1)
        return;
    if (rotate->begin == NULL || rotate->end == NULL)
        return;
    tmp = rotate->end;
    new_end = tmp->next;
    rotate->end = new_end;
    new_end->prev = tmp->prev;
    new_end->prev->next = new_end;
    tmp->prev = rotate->begin;
    tmp->next = rotate->begin->next;
    rotate->begin->next = tmp;
    tmp->next->prev = tmp;
    rotate->begin = tmp;
}

void		rra(t_stack *rotate)
{
    rra_void(rotate);
	ft_putendl("rra");
}

void		rrb(t_stack *rotate)
{
    rrb_void(rotate);
	ft_putendl("rrb");
}

void		rrr(t_stack *a, t_stack *b)
{
    rra_void(a);
	rrb_void(b);
	ft_putendl("rrr");
}
