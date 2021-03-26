#ifndef PUSH_HEADER_H
#define PUSH_HEADER_H

#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TABLE_SIZE	3571
typedef int				t_val;

typedef struct	s_node
{
	struct s_node		*next;
	struct s_node		*prev;
	t_val				val;
	//getter?
}				t_node;

typedef struct s_stack
{
	t_node				*begin;//чтобы двигать только указатель на двусвязном списке
	t_node				*end;//чтобы двигать только указатель на двусвязном списке
	t_node				*(*next)();
	unsigned int		size;//не содержит дубликатов; только инты; достаточно числа типа unsigned_int
}				t_stack;

typedef struct s_program
{
	int			visualize;
}				t_program;

/*
**		parse_nums
*/

int		parse_nums(t_stack *a, t_program *program, int ac, char **av);

/*
**		validate_cl
*/

int			validate_cl(int ac, char **av);

/*
**			validate_arg
*/

int				arg_is_num(char *s);
int				arg_is_flag(char *flag);
int				check_match(int *nums_table, t_node *nodes, int size);

#endif
