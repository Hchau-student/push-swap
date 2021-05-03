#include "swap.h"

void	exec(t_command cmd, t_stack *stack)
{
	cmd.execute(stack);
}

void	exec_2(t_command cmd, t_stack *a, t_stack *b)
{
	cmd.execute_2(a, b);
}
