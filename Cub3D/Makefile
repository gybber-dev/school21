SRCS	= \
			errors/ft_error.c \
			regexp/ft_regexp.c \
			parser/ft_parser.c \
			parser/ft_parse_file.c \
			parser/binary_utils.c \
			parser/ft_parse_map.c \
			main.c \


OBJS		= ${SRCS:.c=.o}

BOBJS		= ${BONUS:.c=.o}

NAME		= ft_cub.a
# NAME		= my_printf

CC			= gcc

RM			= rm -f

HEADER		= ft_cub.h

FLAGS		= #-Wall -Wextra -Werror

.c.o:
			${CC} $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(HEADER) libft.a
			ar rc $(NAME) $(OBJS) ./libft/*.o
			ranlib ft_cub.a

libft.a:
			(cd ./libft/.;$(MAKE))

all:		${NAME}

do_prev:	all
			$(CC) $(FLAGS) main.c ft_cub.a -o cub3d

do:			do_prev clean

clean:
			${RM} ${OBJS} ${BOBJS} *.out
			(cd ./libft/.;$(MAKE) clean)
			(cd ..)
		
fclean:		clean
			${RM} ${NAME} *.a
			(cd ./libft/.;$(MAKE) fclean)
			(cd ..)

re:			fclean all

.PHONY:		all clean fclean re
