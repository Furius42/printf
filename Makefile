# Colors
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BOLD = \033[1m
RESET = \033[0m

# Substitutes
SRCS = src/*.c

OBJS = $(SRCS:.c=.o)

COMPILE = cc -Wall -Werror -Wextra -fPIC

NAME = libftprintf.a

LIB_DIR = ./libft/

LIBFT = libft.a

INCLUDE = ./includes/*.h

all: ${NAME}

${NAME}:${OBJS} ${LIBFT}
	ar rcs ${NAME} ${OBJS}
	echo "$(GREEN)$(BOLD) === Objects added to $(NAME) ===$(RESET)"
	ar rcs ${NAME} ${LIB_DIR}${LIBFT}
	echo "$(GREEN)$(BOLD)=== Libft added to $(NAME) ===$(RESET)"

#${<:%c=%o}

${OBJS}: ${SRCS} ${LIBFT} ${INCLUDE}
	@${COMPILE} -I ${LIB_DIR} -I ./includes -c $< -o $@
	@echo "$(GREEN)$(BOLD) ===Compiled $@ with includes. ===$(RESET)"

${LIBFT}:
	${MAKE} -C ${LIB_DIR}
	echo "$(GREEN)$(BOLD) === $(LIBFT) compiled ===$(RESET)"
	@make clean -C ${LIB_DIR}
	echo "$(RED)$(BOLD) === LIBFT objects purged ===$(RESET)"

clean:
#	make clean -C ${LIB_DIR}
	rm -f ${OBJ}
	rm -f ${LIBFT}

fclean: clean
	make fclean -C ${LIB_DIR}
	rm -f ${NAME}
	rm -f ${LIBFT}

re: fclean all
