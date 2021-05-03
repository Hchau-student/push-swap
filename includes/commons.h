#ifndef COMMONS_H
# define COMMONS_H
# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef int				t_val;
typedef char			t_bool;
# define TRUE	1
# define FALSE	0
# define MAX_INT		    0xFFFFFFFF

typedef struct s_node
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

typedef enum e_commands
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	COMMAND_NUM
}	t_commands;

typedef struct s_program
{
	int			visualize;
	t_list		*commands;
	int			kasino;
}				t_program;

typedef struct s_command
{
	void				(*execute)(struct s_stack *);
	void				(*execute_2)(struct s_stack *, struct s_stack *);
	char				*msg;
}						t_command;

void			error_manager(char *msg);

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
int				arg_is_command(char *arg);
void			get_flag(t_program *program, char *string);

/*
**			command.c
*/

t_command		command(int which);

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

void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

/*
**			markup
*/

void			markup_index(t_stack *stack);
void			markup_greater(t_stack *stack);
void			indexing(t_stack *a);
unsigned int	find_max_len(t_stack *stack);

/*
**		check_sort
*/

int				sorted(t_stack *a, int (*compare)(t_node *, t_node *));
int				compare_greater(t_node *lhs, t_node *rhs);
int				compare_index(t_node *lhs, t_node *rhs);
void			find_markup_head(t_stack *stack);

#endif
