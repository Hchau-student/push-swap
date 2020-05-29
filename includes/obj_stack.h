//
// Created by irka on 27.05.2020.
//

#ifndef PUSH_SWAP_OBJ_STACK_H
#define PUSH_SWAP_OBJ_STACK_H

#include "../libft/libft.h"

typedef char 		boolean;

typedef struct s_swap_number {
	char		is_bignum;
	long		*bignum;
	char		bignum_len;
	long		num;
	char		*to_str;
	boolean		(*more)(struct s_swap_number *, struct s_swap_number *);
	boolean		(*less)(struct s_swap_number *, struct s_swap_number *);
	boolean		(*eq)(struct s_swap_number *, struct s_swap_number *);
	void		(*print)(struct s_swap_number *);
	void    	(*delete)(struct s_swap_number **);
}		t_swap_number;

typedef struct	s_stack
{
	t_twlist				*nums;//попробуем через зацикленные двусвязные списки
	size_t					list_size;//чтобы не зациклиться
	t_twlist				*start_list;//чтобы не зациклиться
	void					(*swap)(struct s_stack **);
	void					(*rotate)(struct s_stack **);
	void					(*rrotate)(struct s_stack **);
}				t_stack;

typedef struct	s_swap
{
	struct s_stack			*a;
	struct s_stack			*b;
	boolean					(*ab_swap)(struct s_swap *);
	void					(*b_swap)(struct s_swap *);
	void					(*a_swap)(struct s_swap *);

	void					(*push_a)(struct s_swap *);
	void					(*push_b)(struct s_swap *);

	boolean					(*ab_rotate)(struct s_swap *);
	void					(*a_rotate)(struct s_swap *);
	boolean					(*b_rotate)(struct s_swap *);

	boolean					(*ab_rrotate)(struct s_swap *);
	void					(*a_rrotate)(struct s_swap *);
	boolean					(*b_rrotate)(struct s_swap *);
}				t_swap;

typedef struct		s_threelst
{
	void				*content;
	size_t				content_size;
	struct s_threelst	*next;
	struct s_threelst	*prev;
	struct s_threelst	*immutable_order;
}						t_threelst;

boolean					create_stack(struct s_stack **new);
void					create_core(t_swap **core);

#endif
