CC = cc

INCLUDES =	includes/ft_printf.h

CFLAGS = -Wall -Wextra -Werror -I${INCLUDES}

NAME = libftprintf.a

FUNCPRINTF =	srcs/ft_printf.c \
				libft/ft_putchar.c \
				libft/ft_putnbr.c \
				libft/ft_putnbr_unsigned.c \
				libft/ft_putstr.c \
				libft/ft_puthexa.c \
				libft/ft_putpointer.c

SRCS = ${FUNCPRINTF}

OBJS = ${SRCS:.c=.o} 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar -rsc ${NAME} ${OBJS}

all: 	${NAME}

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus
