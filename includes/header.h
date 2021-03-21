#ifndef PUSH_HEADER_H
#define PUSH_HEADER_H

#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

/*
**		init_stack
*/

void		init_stack(t_stack *init);

/*
**		parse_nums
*/

int		parse_nums(t_stack *a, int ac, char **av);

/*
**		validate_cl
*/

int			validate_cl(int ac, char **av);

#endif
