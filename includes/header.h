#ifndef PUSH_HEADER_H
#define PUSH_HEADER_H

#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TABLE_SIZE	3571
typedef int				t_val;
#define TRUE	1
#define FALSE	0

typedef struct	s_node
{
	struct s_node		*next;
	struct s_node		*prev;
	unsigned int		index;
	char				markup_greater;
	char				markup_index;
	t_val				val;
	//getter?
}				t_node;

typedef struct s_stack
{
	t_node				*begin;//чтобы двигать только указатель на двусвязном списке
	t_node				*end;//чтобы двигать только указатель на двусвязном списке
	t_node				*cur;
	t_node				*max_len_greater;
	t_node				*max_len_index;
	t_node				*(*next)(struct s_stack *);
	unsigned int		size;//не содержит дубликатов; только инты; достаточно числа типа unsigned_int
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

void		markup_index(t_stack *stack);
void		markup_greater(t_stack *stack);
void		indexing(t_stack *a);

/*
**		algorithm
*/

void		main_cycle(t_stack *a, t_stack *b);

#endif
