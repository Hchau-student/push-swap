#
# # # config:
#
PUSH_SWAP =		push_swap
CHECKER =		checker
NAME =			$(PUSH_SWAP) $(CHECKER)
FLAGS = 		-Wall -Wextra
#FLAGS +=		Werror

#
# # # src:
#
LIB_DIR = 				./libft/
SWAP_SRC_DIR =			./src/swap/**/
SWAP_INC_DIR =			./includes/swap/
CHECKER_SRC_DIR =		./src/checker/
CHECKER_INC_DIR =		./includes/checker

#
# # # obj:
#
all:
	gcc src/**/*.c src/*.c includes/*.h ./libft/libft.a

clean:
	rm -rf a.out ./includes/*.h.gch