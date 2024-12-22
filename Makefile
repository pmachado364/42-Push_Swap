# Color codes
RED    = \033[1;31m
ORANGE = \033[1;33m
RESET  = \033[0m
GREEN  = \033[1;32m
WHITE  = \033[1;37m

# SYMBOLS
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIB_DIR = lib/Libft

# Source, Object, and Library files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
LIBFT = $(LIB_DIR)/libft.a

# Executable name
NAME = push_swap

# Include directories
INCLUDES = -I$(INC_DIR) -I$(LIB_DIR)

# Default target
all: $(NAME)

# Build libft
$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) --no-print-directory --silent

# Build the main program
$(NAME): $(OBJ) $(LIBFT)
	@echo "Building $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ) -L$(LIB_DIR) -lft
	@echo "$(SUCCESS)$(NAME)$(GREEN) compiled successfully.$(RESET)"

# Compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(OBJ:.o=.d)

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) clean --no-print-directory --silent

# Full clean: remove the executable and object files
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean --no-print-directory --silent
	@echo "$(ERROR)$(RED)Executable and objects deleted.$(RESET)"

# Rebuild everything
re: fclean all

# Download checker
download:
	@wget https://cdn.intra.42.fr/document/document/27937/checker_linux && chmod 777 checker_linux
	@echo "$(ORANGE)Downloading checker.$(RESET)"

# Set up visualizer
visualizer:
	@git clone https://github.com/o-reo/push_swap_visualizer.git && \
	cd push_swap_visualizer && \
	mkdir build && \
	cd build && \
	cmake .. && \
	make && \
	./bin/visualizer
	@echo "$(ORANGE)Downloading Visualizer.$(RESET)"

# Phony targets
.PHONY: all clean fclean re