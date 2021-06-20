NAME		= minishell

SRCS	= \
			main.c \

OBJS		= $(patsubst %.c, %.o, $(SRCS))
OS			:= $(shell uname)

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
HEADER		= minishell.h
RM			= rm -f

all:		init ${NAME} $(HEADER)

init:
			@ echo OS detecting... $(OS)
			make -C libft


$(NAME):	$(OBJS) $(HEADER)
			$(CC) $(FLAGS) ${OBJS} -Llibft -lft -o $(NAME)

%.o : %.c
			${CC} $(FLAGS) -c $< -o $@

clean:
			${RM} ${OBJS} ${BOBJS} *.out
			make -C libft clean

fclean:		clean
			$(RM) -rf $(NAME)
			make -C libft fclean

re:			fclean all

norm:
			norminette $(SRCS)
			norminette $(HEADER)
			norminette libft/*.c

.PHONY:		all clean fclean re norm