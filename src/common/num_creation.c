//
// Created by irka on 02.05.2020.
//
#include "../../includes/z_checker.h"
#include <stdio.h>
void    	delete_num(struct s_swap_number **num)
{
	if ((*num)->is_bignum == TRUE)
		free((*num)->bignum);
	free(*num);
}

boolean		more(t_swap_number *lhs, t_swap_number *rhs)
{
	char 	i;
	if ((lhs)->is_bignum == FALSE && rhs->is_bignum == FALSE)
		return (lhs->num > rhs->num ? TRUE : FALSE);
	if (lhs->is_bignum == TRUE && rhs->is_bignum == FALSE)
	{
		if (lhs->bignum[0] < 0 && rhs->num > 0)
			return (FALSE);
		return (TRUE);
	}
	if (rhs->is_bignum == TRUE && lhs->is_bignum == FALSE)
		return (FALSE);
	if (lhs->bignum_len > rhs->bignum_len)
		return (TRUE);
	if (lhs->bignum_len < rhs->bignum_len)
		return (FALSE);
	i = 0;
	while (i < lhs->bignum_len)
	{
		if (lhs->bignum[i] == rhs->bignum[i])
		{
			i++;
			continue ;
		}
		return (lhs->bignum[i] > rhs->bignum[i] ? TRUE : FALSE);
	}
	return (FALSE);
}

boolean		less(t_swap_number *lhs, t_swap_number *rhs)
{
	return (more(lhs, rhs) == TRUE ? FALSE : TRUE);
}

boolean		eq(t_swap_number *lhs, t_swap_number *rhs)
{
	char		i;

	if (lhs->is_bignum != rhs->is_bignum)
		return (FALSE);
	if (lhs->is_bignum == FALSE)
		return (lhs->num == rhs->num ? TRUE : FALSE);
	i = 0;
	while (i < lhs->bignum_len)
	{
		if (lhs->bignum[i] == rhs->bignum[i])
		{
			i++;
			continue ;
		}
		return (FALSE);
	}
	return (TRUE);
}

void	print(t_swap_number *num)
{
	if (num != NULL)
		ft_putendl(num->to_str);
//	printf("and num data: ");
//	if (num->is_bignum == TRUE)
//	{
//		int i = 0;
//		while (i < num->bignum_len)
//		{
//			printf("%ld ", num->bignum[i]);
//			i++;
//		}
//		printf("\nand numlen: %d", num->bignum_len);
//	} else
//		printf("%ld ", num->num);
//	printf("\n");
}

void	create_num(t_swap_number **num)
{
	if (!(*num = (t_swap_number *)malloc(sizeof(t_swap_number))))
		*num = NULL;
	(*num)->delete = delete_num;
	(*num)->more = more;
	(*num)->less = less;
	(*num)->print = print;
	(*num)->eq = eq;
}
