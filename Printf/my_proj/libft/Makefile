SRCS	= ft_strlen.c ft_atoi.c ft_isalpha.c ft_memset.c ft_strlcpy.c ft_isdigit.c			\
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c ft_strchr.c	\
			ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_bzero.c ft_strlcat.c ft_memcpy.c		\
			ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c		\
			ft_substr.c ft_strtrim.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c			\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa_u.c		\
			ft_itoa_hex.c ft_itoa_uhex.c ft_strmultiply.c ft_free.c

BONUS	= ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c 			\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BONUS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -f

HEADER	= -I libft.h

FLAGS	= -Wall -Wextra -Werror

.c.o:	${HEADER}
		${CC} $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs $(NAME) $(OBJS)

all:	${NAME}

clean:
		${RM} ${OBJS} ${BOBJS} *.out
		
fclean:	clean 
		${RM} ${NAME} *.a

re:		fclean all

bonus:	${OBJS} ${BOBJS}
		ar rcs $(NAME) ${OBJS} ${BOBJS}

.PHONY:	all clean fclean re bonus
