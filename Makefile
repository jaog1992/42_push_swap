# Coder Alias
USER_NAME = jde-orma

# Compiler and flags
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

#Colors:

DEF_COLOR	=	\033[0;39m
WHITE		=	\033[0;97m
BLUE		=	\033[0;94m
GREEN		=	\033[0;92m

# Directories
SRC_DIR = source/
INC_DIR = source/
LIBFT_DIR = libraries/libft/
OBJ_DIR = source/
BIN_DIR = ./

# Source files
SRC_FILE = push_swap_main.c push_swap_utilities.c push_swap_moves_push.c push_swap_moves_reverse.c push_swap_moves_rotate.c push_swap_moves_swap.c push_swap_quicksort.c push_swap_sorting.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

# Binary name for your program
CODE_BIN = $(BIN_DIR)push_swap

# Static library
LIBFT = $(LIBFT_DIR)libft.a

# Output executable
NAME = push_swap

# Variable to control if the library has been built
LIBFT_BUILT = no

all: $(CODE_BIN)

$(CODE_BIN): $(LIBFT) $(OBJ)
	@$(CC) $(CCFLAGS) -I$(INC_DIR) $(OBJ) -L$(LIBFT_DIR) -lft -o $@
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) compilation$(WHITE)"

$(LIBFT):
	@if [ "$(LIBFT_BUILT)" = "no" ]; then \
		make -C $(LIBFT_DIR); \
		LIBFT_BUILT=yes; \
	fi

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) .o files removal$(WHITE)"
	@make -C $(LIBFT_DIR) fclean

fclean: clean
	@$(RM) $(CODE_BIN)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) executable and .o files removal$(WHITE)"
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
