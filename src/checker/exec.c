#include "header.h"

void	exec(t_command cmd, t_stack *stack)
{
	cmd.execute(stack);
//	ft_putendl(cmd.msg);
}

void	exec_2(t_command cmd, t_stack *a, t_stack *b)
{
	cmd.execute_2(a, b);
//	ft_putendl(cmd.msg);
}
