#ifndef PUSH_HEADER_H
#define PUSH_HEADER_H

#include "commons.h"

#define TBL_SZ  	    3571

typedef struct	s_node
{
	struct s_node		*next;
	struct s_node		*prev;
	unsigned int		index;
	char				markup_greater;
	char				markup_index;
	t_val				val;
}				t_node;

typedef struct s_iter
{
	t_node				*cur;
	t_node				**begin;
	t_node				**end;
	unsigned int		*max_size;
	unsigned int		cur_size;
	t_node				*(*next_iter)(struct s_iter *);
	t_node				*(*prev)(struct s_iter *);
}				t_iter;

typedef struct s_stack
{
	t_node				*begin;
	t_node				*end;
	t_node				*max_len_greater;
	t_node				*max_len_index;
	t_node				*(*next_iter)(t_iter *);
	t_node				*(*prev_iter)(struct s_iter *);
	unsigned int		size;
}				t_stack;

typedef struct s_program
{
	int			visualize;
}				t_program;

/*
**			parse_nums
*/

int				parse_nums(t_stack *a, t_program *program, int ac, char **av);

/*
**			validate_arg
*/

int				arg_is_num(char *s);
int				arg_is_flag(char *flag);
int				check_match(int *nums_table, t_node *nodes, int size);

/*
**			commands_1
*/

void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);

/*
**			commands_2
*/

void			pb(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);

/*
**			commands_3
*/

void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);

/*
**			commands_4
*/

void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

/*
**			markup
*/

void				markup_index(t_stack *stack);
void				markup_greater(t_stack *stack);
void				indexing(t_stack *a);
unsigned int		find_max_len(t_stack *stack);

/*
**		algorithm
*/

void		main_cycle(t_stack *a, t_stack *b);

/*
**		check_sort
*/

int			sorted(t_stack *a, int (*compare)(t_node *, t_node *));
int			compare_greater(t_node *lhs, t_node *rhs);
int			compare_index(t_node *lhs, t_node *rhs);
void		find_markup_head(t_stack *stack);

/*
**		choose_element
*/

void		choose_element(t_stack *a, t_stack *b);

/*
**		choose_element_count
*/

void			count_commands_a(unsigned int *rota, unsigned int *rrota, t_stack *stack, t_node *elem);
void			count_commands_b(unsigned int *rrota, unsigned int *rota, t_stack *b, t_node *elem);
unsigned int	count_element_a(t_stack *a, t_stack *b, t_node *node);

/*
**		iter
*/

t_node		*next_iter_a(t_iter *iter);
t_node		*next_iter_b(t_iter *iter);
t_node		*prev_iter_a(t_iter *iter);
t_node		*prev_iter_b(t_iter *iter);
t_iter		*new_iter(t_stack *stack);
void		destroy_iter(t_iter **iter);

/*
** 		prepare_a
*/

void		prepare_a(t_stack *a, t_stack *b);

/*
**		get_from_b
*/

void		get_from_b(t_stack *a, t_stack *b);

#endif
