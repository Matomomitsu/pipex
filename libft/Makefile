SRCS = ft_strlen.c \
				ft_bzero.c \
				ft_substr.c \
				ft_calloc.c \
				ft_realloc.c \
				ft_strlcpy.c \
				ft_strjoin.c \
				ft_printf.c \
				ft_putstr_fd.c \
				ptr_conversion.c \
				int_conversion.c \
				unsigint_conversion.c \
				hex_conversion.c \
				ft_putchar_fd.c \
				ft_itoa_base.c \
				ft_itoa.c \
				ft_split.c \
				str_conversion.c \
				ft_strchr.c \
				get_next_line.c \
				ft_strdup.c \
				ft_strncmp.c \


NAME = libft.a

CC = cc

LIB = ar -rcs

CFLAGS = -Wall -Werror -Wextra

HEADER = libft.h

OBJS = 		${SRCS:.c=.o}

OBJS_BONUS =	${SRCS_BONUS:.c=.o}

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
				${LIB} ${NAME} ${OBJS}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus rebonus
