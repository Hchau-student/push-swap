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

void	error_manager(char *msg);

#endif //PUSH_SWAP_COMMONS_H
