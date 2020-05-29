
#ifndef PUSH_SWAP_Z_CHECKER_H
#define PUSH_SWAP_Z_CHECKER_H
#include "obj_stack.h"
#include <limits.h>
#include "z_checker_error.h"
#include "../libft/libft.h"

//#define BOOL	char
#define TRUE	1
#define FALSE	0

typedef char 		boolean;

void				create_num(t_swap_number **num);

void				checker_exit(char *reason);
t_swap_number		*check_valid(char *check_num, size_t *index);
t_twlist			*check_num_arr(char **av, int ac);
t_swap_number		*str_to_num(char *s, char *success, size_t *index);

//void	print(t_swap_number *num);

#endif //PUSH_SWAP_Z_CHECKER_H
