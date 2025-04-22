# Colors
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BOLD = \033[1m
RESET = \033[0m

# Substitutes
SRCS = src/ft_printf.c

OBJS = $(SRCS:.c=.o)

COMPILE = cc -Wall -Werror -Wextra -fPIC

NAME = libftprintf.a

LIB_DIR = ./libft/

LIBFT = libft.a

INCLUDE = -I./includes

LIBFT_INCLUDE = -I.${LIB_DIR}libft.h

all: ${NAME}

${LIBFT}:
	${MAKE} -C ${LIB_DIR}
	cp ${LIB_DIR}$@ ./
	@echo "$(GREEN)$(BOLD)$(LIBFT) acquired$(RESET)"
	make clean -C ${LIB_DIR}

${NAME}:${OBJS} ${LIBFT}
	@ar rc ${NAME} ${OBJS} ${LIBFT}
	@echo "$(GREEN)$(BOLD)Library $(NAME) created.$(RESET)"

#${<:%c=%o}

src/%.o: src/%.c
	@${COMPILE} ${INCLUDE} -c $< -o $@
	@echo "Compiled $@ with includes.$(RESET)"

clean:
#	make clean -C ${LIB_DIR}
	rm -f ${OBJ}
	rm -f ${LIBFT}

#fclean: clean
#	make fclean -C ${LIB_DIR}
#	rm -f ${NAME}
#	rm -f ${LIBFT}
#
#re: fclean all
