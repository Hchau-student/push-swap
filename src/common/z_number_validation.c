//
// Created by irka on 02.05.2020.
//
#include <stdio.h>
#include "../../includes/z_checker.h"

long					str_to_int(char **gl_str, char *success, int counter)
{
//	int 	counter;
	long 	num_res;
	char 	*str;

	str = *gl_str;
	num_res = 0;
	while (counter && *str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
			break ;
		if (*str < '0' || *str > '9')
		{
			printf("%s", str);
			*success = FALSE;
			return (0);
		}
		num_res = num_res * 10 + (*str - '0');
		counter--;
		str++;
	}
	*gl_str = str;
	return (num_res);
}

void				check_bignum(t_swap_number **num_res)
{
	t_swap_number	*num;
	int 			i = 0;
//	int 			real_leight = num->bignum_len;

	num = *num_res;
	if (num->bignum_len == 1 || num->bignum[0] == 0)
	{
		num->num = num->bignum[0];
		num->is_bignum = FALSE;
		num->bignum_len = -1;
		free(num->bignum);
	}
	else if (num->bignum_len <= 0)
	{
		num->num = 0;
		num->is_bignum = FALSE;
		num->bignum_len = -1;
		free(num->bignum);
	}
	*num_res = num;
}

void				create_bignum(t_swap_number **number, char *s, boolean *success)
{
	int		i;
	t_swap_number	*num_res;
	num_res = *number;
	char 	sign;
	sign = *s == '-' ? -1 : 1;
	s += (*s == '-' || *s == '+') ? 1 : 0;

	num_res->is_bignum = TRUE;
	num_res->bignum_len = ft_strlen(num_res->to_str) / ((sizeof(long)) * 2);//размер ячейки
	num_res->bignum_len += ft_strlen(num_res->to_str) % ((sizeof(long)) * 2) == 0 ? 0 : 1;
	num_res->bignum = (long *)malloc(sizeof(long) * (num_res->bignum_len));
	i = 0;
	if (ft_strlen(num_res->to_str) % ((sizeof(long)) * 2) != 0)
	{
		num_res->bignum[i++] = str_to_int(&s, success, ft_strlen(num_res->to_str) % ((sizeof(long)) * 2)) * sign;
		i++;
		if (num_res->bignum[0] == 0) {
			i = 0;
			num_res->bignum_len--;
		}
	}
	while (i < num_res->bignum_len)
	{
		num_res->bignum[i] = str_to_int(&s, success, ((sizeof(long))) * 2) * sign;
		if (i == 0 && num_res->bignum[0] == 0)
		{
			i--;
			num_res->bignum_len--;
		}
		++i;
		if (!*s || *success == FALSE)
		{
			check_bignum(number);
			return;
		}
	}
	check_bignum(number);
}

char				*new_num_str(const char *str, size_t *index)
{
	char *res;
	char *iter;
	res = (char *)malloc(sizeof(char) * ft_strlen(str));

	iter = res;
	while (*str)
	{
		*index = *index + 1;
		*iter = *str;
		if (*str == ' ' || *str == '\n' || *str == '\t')
			break;
		str++;
		iter++;
	}
	*iter = '\0';
	return (res);
}

t_swap_number		*str_to_num(char *s, char *success, size_t *index)
{
	t_swap_number		*num_res;
	char 				sign;

	s += *index;
	while (*s && *s == ' ') {
		s++;
		*index += 1;
	}
	if (!*s)
		return (NULL);
	create_num(&num_res);
	num_res->to_str = new_num_str(s, index);
	if (ft_strlen(num_res->to_str) > (sizeof(long) * 2))
		create_bignum(&num_res, s, success);
	else
	{
		sign = *s == '-' ? -1 : 1;
		s += (*s == '-' || *s == '+') ? 1 : 0;
		num_res->num = str_to_int(&s, success, (sizeof(long) * 2)) * sign;
		num_res->is_bignum = FALSE;
	}
	if (*success == FALSE)
	{
		num_res->delete(&num_res);
		checker_exit(NUM_SIMBOL_ERROR);
	}
//	while (s[*index] && (s[*index] == ' ' || s[*index] == '\n' || s[*index] == '\t'))
//		*index += 1;
	return (num_res);
}
