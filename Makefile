SRCS = 	srcs/converters.c \
		srcs/ft_printf.c \
		srcs/hex_functions.c \
		srcs/number_functions.c \
		srcs/print_format.c \
		srcs/ptr_functions.c \
		srcs/string_functions.c \
		srcs/unumber_functions.c \
		srcs/utils.c

INCLUDES			= includes/ft_printf.h

OBJS				= ${SRCS:.c=.o}

NAME				= libftprintf.a

CC					= cc

RM					= rm -f

CFLAGS				= -Wall -Wextra -Werror

all:				${NAME}

.c.o:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${OBJS}:			${INCLUDES}

$(NAME):			${INCLUDES} ${OBJS}
					ar -rcs ${NAME} ${OBJS}

clean:
					${RM} ${OBJS}

fclean:				clean
					${RM} ${NAME}

re:					fclean all

.PHONY:				all clean fclean re