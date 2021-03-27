NAME = ../../tests
OBJ_DIR = tests_obj
SRC_DIR = ../swap
SRC_TESTS_DIR = ./
INCL_DIR = ../../includes
LIBFT_FLAGS = -L ../../libft -lft

C_FILES = commands_1.c \
                      parse_nums.c validate_cl.c \
                      validate_arg.c commands_2.c \
                      commands_3.c commands_4.c

C_TESTS_FILES = main.c validate_cl.c parse_nums_test.c

CFLAGS = -Wall -Wextra #-Werror

OBJ_FILES = $(C_FILES:.c=.o)
OBJ_FILES_TESTS = $(C_TESTS_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/1_,$(OBJ_FILES))
RAW_OBJ_FILES_TESTS = $(addprefix $(OBJ_DIR)/2_,$(OBJ_FILES_TESTS))

DEPS = $(RAW_OBJ_FILES:.o=.d)
DEPS_TESTS = $(RAW_OBJ_FILES_TESTS:.o=.d)

all: $(OBJ_DIR) $(NAME) $(NOT_EXIST)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): ../../libft/libft.a $(RAW_OBJ_FILES) $(RAW_OBJ_FILES_TESTS)
	gcc -o $(NAME) $(RAW_OBJ_FILES) $(RAW_OBJ_FILES_TESTS) $(LIBFT_FLAGS) -I $(INCL_DIR)

$(NOT_EXIST):
	@make -C ../../libft

-include $(DEPS_TESTS)
$(OBJ_DIR)/2_%.o: $(SRC_TESTS_DIR)/%.c | $(OBJ_DIR)
	gcc  $(CFLAGS) -I $(INCL_DIR) -I ../../libft -c $< -o $@

-include $(DEPS)
$(OBJ_DIR)/1_%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc  $(CFLAGS) -I $(INCL_DIR) -I ../../libft -c $< -o $@

re: fclean all
