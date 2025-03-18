SRCS	=	libftprintf.c \
			convert.c

OBJS	= ${SRCS:%c=%o}			# Object files: .o files corresponding to .c files

INCLUDES = libft.h

CFLAGS	= cc -Wall -Wextra -Werror		# Flags

NAME = libft.a

${NAME}: ${OBJS}				# Rule to create the static library
	@ar rc ${NAME} ${OBJS}
	@echo "Library $(NAME) created."

%.o: %.c						# Rule to compile .c files into .o files
	@${CFLAGS} -c $< -o ${<:%c=%o}
	@echo "Compiled $@."

all: ${NAME}

clean:							# Rule to remove object files
	@rm -f ${OBJS}
	@echo "Object files removed."

fclean: clean					# Rule to remove the library and object files
	@rm -f ${NAME}
	@echo "Library $(NAME) and object files removed."

re: fclean all					# Rule to clean and rebuild everything

.PHONY: all clean fclean re		# Ensures these targets are not treated as files
