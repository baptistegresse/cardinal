NAME        :=   cardinal

INC         :=   cardinal.h
INC_DIR     :=   includes/

HEADERS     := $(addprefix $(INC_DIR), $(INC))

SRC_DIR     :=   sources/
SRC         :=   main.c parser.c controller.c utils/itoa.c utils/list.c  \
                utils/split.c utils/strjoin.c handles/handle_chain.c   \
                handles/handle_direction.c handles/handle_erase.c     \
                handles/handle_restart.c handles/handle_cancel.c

OBJ_DIR     :=   build/
OBJ         :=   $(SRC:%.c=$(OBJ_DIR)%.o)

# Compiler options
CC          :=   gcc
CC_FLAGS    :=   -Wextra -Werror -Wall

# define standard colors
_END        :=   \x1b[0m
_BOLD       :=   \x1b[1m
_UNDER      :=   \x1b[4m
_REV        :=   \x1b[7m
_GREY       :=   \x1b[30m
_RED        :=   \x1b[31m
_GREEN      :=   \x1b[32m
_YELLOW     :=   \x1b[33m
_BLUE       :=   \x1b[34m
_PURPLE     :=   \x1b[35m
_CYAN       :=   \x1b[36m
_WHITE      :=   \x1b[37m

all: $(NAME)

$(NAME): $(OBJ) Makefile
		@$(CC) $(CC_FLAGS) $(OBJ) -o $@
		@echo "> cardinal Done!\n"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(@D)
	@echo "$(_GREEN)compiling: $<$(_END)"
	@$(CC) $(CC_FLAGS) -I$(INC_DIR) -c $< -o $@

# clean commands
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "remove $(NAME)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
