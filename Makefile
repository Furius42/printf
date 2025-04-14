# Colors
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BOLD = \033[1m
RESET = \033[0m

# Substitutes
NAME = libftprintf.a

SRCS = src/ft_printf.c src/convert.c src/convert_int.c src/convert_str.c src/convert_p.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes -I libft
COMPILE = cc -Wall -Werror -Wextra

LIB_DIR = ./libft
LIBFT = $(LIB_DIR)/libft.a

# Rules

all: ${NAME}

${LIBFT}:
	@${MAKE} -C ${LIB_DIR}
	@echo "$(GREEN)$(BOLD) === $(LIBFT) built ===$(RESET)"
	@make clean -C ${LIB_DIR}
	@echo "$(RED)$(BOLD) === LIBFT objects purged ===$(RESET)"

${NAME}: ${LIBFT} ${OBJS}
	@echo "$(GREEN)$(BOLD) === $(NAME) Built with ft_printf and libft ===$(RESET)"
	cp ${LIBFT_DIR}${LIBFT} ${NAME}
	ar rcs ${NAME} ${OBJS}

%.o: %.c
	@${COMPILE} ${INCLUDES} -c $< -o $@
	@echo "$(GREEN) === Compiled $<      to      $@ ===$(RESET)"

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIB_DIR} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIB_DIR} fclean

re: fclean all
