SRCS	= main.c ft_strlen.c ft_atoi.c ft_isalpha.c ft_memset.c ft_strlcpy.c ft_isdigit.c	\
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c ft_strchr.c	\
			ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_bzero.c ft_strlcat.c ft_memcpy.c		\
			ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c		\
			ft_substr.c ft_strtrim.c ft_strjoin.c ft_split.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

GCC		= gcc

RM		= rm -f

FLAGS	= -Wall -Wextra -Werror

.c.o:	${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs $(NAME) $(OBJS)
		${GCC} ${FLAGS} ${OBJS} -include libft.h -o test

all:	${NAME}

clean:
		${RM} ${OBJS} *.out
		
fclean:	clean 
		${RM} ${NAME} *.a

re:		fclean all

.PHONY:	all clean fclean re
