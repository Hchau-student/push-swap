PINK = \033[38;2;200;150;200m
BLUE = \033[38;2;200;200;250m
RED = \033[38;2;200;30;70m
YELLOW = \033[38;2;200;200;50m
GREEN = \033[38;2;0;200;0m

NAME = $(SWAP)
SWAP = push_swap
CHECKER = checker
OBJ_DIR = ./obj
SRC_SWAP_DIR = ./src/swap
INCL_DIR = ./includes

C_FILES = main.c \
            parse_nums.c validate_arg.c \
            commands_1.c commands_2.c \
            commands_3.c commands_4.c \
            algorithm.c markup.c \
            find_markup_head.c check_sort.c \
            next.c choose_element.c

OBJ_FILES = $(C_FILES:.c=.o)
RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))
LIBFT_FLAGS = -L libft/ -lft
NOT_EXIST	= tfbil

CFLAGS = -Wall -Wextra #-Werror

###################
####### all #######
###################

all: $(OBJ_DIR) $(NAME) $(NOT_EXIST)

$(NOT_EXIST):
	@make -C ./libft

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES)
	@make -sC ./libft
	@gcc $(RAW_OBJ_FILES) $(LIBFT_FLAGS) -o $(NAME)

#### К о м п и л я ц и я ####

$(OBJ_DIR)/%.o: $(SRC_SWAP_DIR)/%.c $(INCL_DIR)/*.h
	@gcc $(CFLAGS) -I $(INCL_DIR) -I ./libft -c $< -o $@

clean:
	@rm -rf $(RAW_OBJ_FILES)
	@rm -rf ./libft/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@rm -rf ./libft/libft.a

re: fclean all

########################
####### tests ##########
########################

test:
	rm -rf tests
	rm -rf ./src/tests_src/tests_obj
	make -sC ./src/tests_src
	./tests