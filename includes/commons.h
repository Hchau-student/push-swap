#ifndef PUSH_SWAP_COMMONS_H
#define PUSH_SWAP_COMMONS_H

#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef int				t_val;
typedef char			t_bool;
#define TRUE	1
#define FALSE	0
#define MAX_INT		    0xFFFFFFFF

typedef enum			e_commands
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
}						t_commands;

struct s_stack;

void	error_manager(char *msg);

typedef struct			s_command
{
	void				(*execute)(struct s_stack *);
	void				(*execute_2)(struct s_stack *, struct s_stack *);
	char				*msg;
}						t_command;
t_command		command(int which);

#endif //PUSH_SWAP_COMMONS_H
