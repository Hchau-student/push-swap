PINK = \033[38;2;200;150;200m
BLUE = \033[38;2;200;200;250m
RED = \033[38;2;200;30;70m
YELLOW = \033[38;2;200;200;50m
GREEN = \033[38;2;0;200;0m

NAME = $(SWAP) $(CHECKER)
SWAP = push_swap
CHECKER = checker
OBJ_DIR = ./obj
SRC_SWAP_DIR = ./src/swap
SRC_COMMONS_DIR = ./src/commons
SRC_CHECKER_DIR = ./src/checker
INCL_DIR = ./includes

C_FILES = main.c \
            algorithm.c markup.c \
            check_sort.c prepare_a.c get_from_b.c \
            choose_element.c choose_element_count.c \
            find_max_len.c execute_command.c

C_COMMON_FILES = error.c parse_nums.c validate_arg.c \
                 iter.c iter_b.c \
                 commands_1.c commands_2.c \
                 commands_3.c commands_4.c \

C_CHECKER_FILES = checker.c

OBJ_FILES = $(C_FILES:.c=.o)
OBJ_FILES_COMMON = $(C_COMMON_FILES:.c=.o)
OBJ_FILES_CHECKER = $(C_CHECKER_FILES:.c=.o)
RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))
RAW_OBJ_FILES_COMMON = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES_COMMON))
RAW_OBJ_FILES_CHECKER = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES_CHECKER))
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

$(SWAP): $(RAW_OBJ_FILES) $(RAW_OBJ_FILES_COMMON)
	@make -sC ./libft
	@gcc $(RAW_OBJ_FILES) $(RAW_OBJ_FILES_COMMON) $(LIBFT_FLAGS) -o $(SWAP)

$(CHECKER): $(RAW_OBJ_FILES_CHECKER) $(RAW_OBJ_FILES_COMMON)
	@make -sC ./libft
	@gcc $(RAW_OBJ_FILES_CHECKER) $(RAW_OBJ_FILES_COMMON) $(LIBFT_FLAGS) -o $(CHECKER)

#### К о м п и л я ц и я ####

$(OBJ_DIR)/%.o: $(SRC_SWAP_DIR)/%.c $(INCL_DIR)/*.h
	@gcc $(CFLAGS) -I $(INCL_DIR) -I ./libft -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_CHECKER_DIR)/%.c $(INCL_DIR)/*.h
	@gcc $(CFLAGS) -I $(INCL_DIR) -I ./libft -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_COMMONS_DIR)/%.c $(INCL_DIR)/*.h
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