NAME		= cub3D

SRCS	= \
			errors/ft_error.c \
			regexp/ft_regexp.c \
			parser/ft_parser.c \
			parser/ft_parse_file.c \
			parser/binary_utils.c \
			parser/ft_parse_map.c \
			parser/ft_validator.c \
			main.c \


OBJS		= ${SRCS:.c=.o}

BOBJS		= ${BONUS:.c=.o}

CC			= gcc

RM			= rm -f

HEADER		= ft_cub.h

FLAGS		= #-Wall -Wextra -Werror

.c.o:
			${CC} $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(HEADER) init

all:		${NAME}

init:
			make -C libft
			make -C libmlx

do_prev:	all
			$(CC) $(FLAGS) $(OBJS) $(HEADER) -o $(NAME)

do:			do_prev clean

inc:		all
			$(CC) $(FLAGS) main.c -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

clean:
			${RM} ${OBJS} ${BOBJS} *.out
			(cd ./libft/.;$(MAKE) clean)
			(cd ..)
		
fclean:		clean
			(cd ./libft/.;$(MAKE) fclean)
			(cd ..)

re:			fclean all

.PHONY:		all clean fclean re
