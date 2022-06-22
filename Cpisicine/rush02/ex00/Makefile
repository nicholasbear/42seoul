SRCS	= converter.c main.c utilstr.c dictionary00.c utildictionary.c dictionary01.c utilfile.c

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC		= gcc

RM		= rm -f

CFLAGS 	= -Wall -Werror -Wextra

all:		${NAME}

.c.o:	
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}


clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
