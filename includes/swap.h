#ifndef SWAP_H
# define SWAP_H
# include "commons.h"
# define TBL_SZ 3571

/*
**		algorithm
*/

void			main_cycle(t_stack *a, t_stack *b);

/*
**		choose_element
*/

void			choose_element(t_stack *a, t_stack *b);

/*
**		choose_element_count
*/

void			count_commands_a(unsigned int *rota, unsigned int *rrota,
					t_stack *stack, t_node *elem);
void			count_commands_b(unsigned int *rrota, unsigned int *rota,
					t_stack *b, t_node *elem);
unsigned int	count_element_a(t_stack *a, t_stack *b, t_node *node);

/*
**		iter
*/

t_node			*next_iter_a(t_iter *iter);
t_node			*next_iter_b(t_iter *iter);
t_node			*prev_iter_a(t_iter *iter);
t_node			*prev_iter_b(t_iter *iter);
t_iter			*new_iter(t_stack *stack);
void			destroy_iter(t_iter **iter);

/*
** 		prepare_a
*/

void			prepare_a(t_stack *a, t_stack *b);

/*
**		get_from_b
*/

void			get_from_b(t_stack *a, t_stack *b);
void			exec(t_command cmd, t_stack *stack);
void			exec_2(t_command cmd, t_stack *a, t_stack *b);
int				get_command(char *arg);

#endif
