CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS = so_long.c \
		get_next_line.c \
		get_next_line_utils.c \
		check_map.c \
		image.c \
		key_press.c \
		util.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L./ -lmlx -framework OpenGL -framework Appkit

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I./ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re