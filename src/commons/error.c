#include "swap.h"

void	error_manager(char *msg)
{
	ft_putstr("\033[38;2;139;20;39m");
	ft_putendl(msg);
	exit(0);
}
