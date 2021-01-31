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

OBJS		= $(patsubst %.c, %.o, $(SRCS))

CC			= gcc
FLAGS		= #-Wall -Wextra -Werror
HEADER		= ft_cub.h

RM			= rm -f

OPTFLAGS    = -O2 # оптимизация при комплиляции

%.c : %.o:
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

# commands
# http://rus-linux.net/nlib.php?name=/MyLDP/algol/gnu_make/gnu_make_3-79_russian_manual.html#SEC77