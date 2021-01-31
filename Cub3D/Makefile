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

all:		init ${NAME}

init:
			@ echo "......init......"
			make -C libft
			make -C libmlx

$(NAME):	$(OBJS) $(HEADER)
# MAC:
#  			$(CC) $(FLAGS) $? $(HEADER) -Llibft -lft -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
# Lnx:
			$(CC) $(FLAGS) $(OBJS) $(HEADER) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext -o $(NAME)

%.o : %.c
			${CC} $(FLAGS) -c $< -o $@

# inc:		all
# 			$(CC) $(OBJS) $(HEADER) -Llibft -lft -L.minilibx_mms -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# LINUX:
	# $(CC) $(FLAGS) main.c -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

clean:
			${RM} ${OBJS} ${BOBJS} *.out
			make -C libft clean
		
fclean:		clean
			$(RM) -rf $(NAME)
			make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re

# commands
# http://rus-linux.net/nlib.php?name=/MyLDP/algol/gnu_make/gnu_make_3-79_russian_manual.html#SEC77