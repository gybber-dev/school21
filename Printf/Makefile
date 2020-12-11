SRCS	= main.c

# BONUS	= ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c 			\
# 			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BONUS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

RM		= rm -f

HEADER	= -I printf.h

FLAGS	= -Wall -Wextra -Werror

.c.o:	${HEADER}
		${CC} $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs $(NAME) $(OBJS)

all:	${NAME}

do:		${OBJS}
		${CC} $(FLAGS) $(OBJS) -c $< -o ${<:.c=.o}

clean:
		${RM} ${OBJS} ${BOBJS} *.out
		
fclean:	clean 
		${RM} ${NAME} *.a

re:		fclean all

bonus:	${OBJS} ${BOBJS}
		ar rcs $(NAME) ${OBJS} ${BOBJS}

do:     #{}
.PHONY:	all clean fclean re bonus
