# Colors
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BOLD = \033[1m
RESET = \033[0m

# Substitutes
NAME = libftprintf.a

SRCS = src/ft_printf.c src/ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes -I libft
COMPILE = cc -Wall -Werror -Wextra -g

LIB_DIR = ./libft
LIBFT = $(LIB_DIR)/libft.a

# Rules
TEST = a.out
TEST_SRC = main.c
TEST_OBJ = $(TEST_SRC:.c=.o)

# Default target
all: ${NAME}

# Build libft (ensure it is built before libftprintf)
${LIBFT}:
	@$(MAKE) -C ${LIB_DIR}
	@echo "$(GREEN)$(BOLD) === $(LIBFT) built ===$(RESET)"

# Build libftprintf.a and link libft.a
${NAME}: ${LIBFT} ${OBJS}
	@echo "$(GREEN)$(BOLD) === $(NAME) Built with ft_printf and libft ===$(RESET)"
	ar rcs ${NAME} ${OBJS}
	@echo "$(GREEN) === ${NAME} built ===$(RESET)"

# Compile .o files from .c files
%.o: %.c
	@${COMPILE} ${INCLUDES} -c $< -o $@
	@echo "$(GREEN) === Compiled $< to $@ ===$(RESET)"

# Build the test program
test: 	${NAME} $(TEST_OBJ) $(LIBFT)
	cc -g -o $(TEST) $(TEST_OBJ) $(NAME) $(LIBFT) -I includes -lc
	@echo "$(YELLOW)$(BOLD) === Test executable '$(TEST)' built ===$(RESET)"

# Clean object files and libft
clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIB_DIR} clean
	@echo "$(RED)$(BOLD) === Cleaned libft and libftprintf ===$(RESET)"

# Clean test files
testclean:
	@rm -f $(TEST_OBJ)

# Clean everything including the library
fclean: clean testclean
	@rm -f ${NAME}
	@${MAKE} -C ${LIB_DIR} fclean

# Rebuild everything
re: fclean all

# Compile all incl. main.c and clean up.. leaving just executable a.out
out: all test fclean