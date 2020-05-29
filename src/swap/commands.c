#include "../../includes/z_checker.h"

//

boolean					ab_swap(t_swap *data)
{
	data->a->swap(&data->a);
	data->b->swap(&data->b);
	write(1, "ss\n", 3);
	return TRUE;
}

void					a_swap(t_swap *data)
{
	data->a->swap(&data->a);
	write(1, "sa\n", 3);
}

void					a_rotate(t_swap *data)
{
	data->a->rotate(&data->a);
	write(1, "ra\n", 3);
}

boolean					b_rotate(t_swap *data)
{
	data->b->rotate(&data->b);
	write(1, "rb\n", 3);
}

boolean					b_rrotate(t_swap *data)
{
	data->b->rrotate(&data->b);
	write(1, "rrb\n", 3);
}

void					a_rrotate(t_swap *data)
{
	data->a->rrotate(&data->a);
	write(1, "rra\n", 3);
}

void					b_swap(t_swap *data)
{
	data->b->swap(&data->b);
	write(1, "sb\n", 3);
}

boolean					ab_rotate(t_swap *data)
{
	data->a->rotate(&data->a);
	data->b->rotate(&data->b);
	write(1, "rr\n", 3);
	return TRUE;
}
boolean					ab_rrotate(t_swap *data)
{
	data->a->rrotate(&data->a);
	data->b->rrotate(&data->b);
	write(1, "rrr\n", 4);
	return TRUE;
}

void					push_a(t_swap *data)
{
	t_twlist	*tmp;

	if (data->b->list_size > 0)
	{
		tmp = data->b->nums->next;//this will be the topest list
		t_twlist	*tmp2;
		if (data->a->nums)
			tmp2 = data->a->nums->prev;
		else
			tmp2 = NULL;
		ft_twlstadd(&data->a->nums, data->b->nums);//add tmp to the top of b
		//зациклить лист б
		if (tmp2)
		{
			data->a->nums->prev = tmp2;
			tmp2->next = data->a->nums;
		} else {
			data->a->nums->next = data->a->nums;
			data->a->nums->prev = data->a->nums;
		}
		data->b->list_size--;
		data->a->list_size++;
		if (data->b->list_size == 0)
		{
			data->b->nums = NULL;
			write(1, "pa\n", 3);
			return;
		}
		data->b->nums = tmp;
		data->b->nums->prev = data->b->nums->prev->prev;
		data->b->nums->prev->next = data->b->nums;
	}
	write(1, "pa\n", 3);
}

void					push_b(t_swap *data)
{
	t_twlist	*tmp;
	if (data->a->list_size > 0)
	{
		tmp = data->a->nums->next;//this will be the topest list
		t_twlist	*tmp2;
		if (data->b->nums)
			tmp2 = data->b->nums->prev;
		else
			tmp2 = NULL;
		ft_twlstadd(&data->b->nums, data->a->nums);//add tmp to the top of b
		//зациклить лист б
		if (tmp2)
		{
			data->b->nums->prev = tmp2;
			tmp2->next = data->b->nums;
		} else {
			data->b->nums->next = data->b->nums;
			data->b->nums->prev = data->b->nums;
		}
		data->a->list_size--;
		data->b->list_size++;
		if (data->a->list_size == 0)
		{
			data->a->nums = NULL;
			write(1, "pb\n", 3);
			return;
		}
		data->a->nums = tmp;
		data->a->nums->prev = data->a->nums->prev->prev;
		data->a->nums->prev->next = data->a->nums;
	}
	write(1, "pb\n", 3);
}

void					create_core(t_swap **core)
{
	*core = (t_swap *)malloc(sizeof(t_swap));
	(*core)->ab_swap = ab_swap;
	(*core)->a_swap = a_swap;
	(*core)->b_swap = b_swap;

	(*core)->ab_rotate = ab_rotate;
	(*core)->a_rotate = a_rotate;
	(*core)->b_rotate = b_rotate;

	(*core)->ab_rrotate = ab_rrotate;
	(*core)->a_rrotate = a_rrotate;
	(*core)->b_rrotate = b_rrotate;

	(*core)->push_a = push_a;
	(*core)->push_b = push_b;
}