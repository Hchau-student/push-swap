cmake_minimum_required(VERSION 3.19)
project(push_swap1 C)

set(CMAKE_C_STANDARD 11)

include_directories(libft)
include_directories(includes)

add_executable(push_swap1
        includes/header.h
        includes/commons.h
        includes/checker.h
        libft/libft.h
        libft/get_next_line.h
        libft/get_next_line.c
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_freematr.c
        libft/ft_is_whitespace.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lstadd.c
        libft/ft_lstclr.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_one_delim.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strcdup.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strcpy_return.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_swap.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_twlstadd.c
        libft/ft_twlstclr.c
        libft/ft_twlstdel.c
        libft/ft_twlstdel_backw.c
        libft/ft_twlstdelone.c
        libft/ft_twlstiter.c
        libft/ft_twlstmap.c
        libft/ft_twlstnew.c

        src/checker/checker.c
        src/checker/exec.c
        src/checker/parse_commands.c
#        src/swap/algorithm.c
#                src/swap/choose_element.c
#                src/swap/choose_element_count.c
#                src/swap/execute_command.c
#                src/swap/find_max_len.c
#                src/swap/get_from_b.c
#                src/swap/iter.c
#                src/swap/iter_b.c
#                src/swap/main.c
#                src/swap/prepare_a.c

        src/commons/iter.c
        src/commons/iter_b.c
                src/commons/check_sort.c
                src/commons/command.c
                src/commons/commands_1.c
                src/commons/commands_2.c
                src/commons/commands_3.c
                src/commons/commands_4.c
                src/commons/error.c
                src/commons/markup.c
                src/commons/parse_nums.c
                src/commons/validate_arg.c)