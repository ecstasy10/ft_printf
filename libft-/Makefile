SRC_DIR = SRC_DIR
INCLUDES=./
NAME	= libft.a
OBJS	= *.c
CC		= gcc -c -Wall -Wextra -Werror
CCTWO	= ar rc libft.a *.o
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
all:
			${CC} ${OBJS}
			${CCTWO}
$(NAME):
			${CC} ${OBJS} ${CCTWO}
fclean:		clean
			${RM} ${NAME}
clean:
			${RM} *.o
re:			fclean all
.PHONY:		all clean fclean re
