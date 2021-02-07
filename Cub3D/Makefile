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
			window/window.c \
			window/player.c \
			window/map.c \
			window/moving.c \

OBJS		= $(patsubst %.c, %.o, $(SRCS))
OS			:= $(shell uname)


CC			= gcc
FLAGS		= #-Wall -Wextra -Werror
HEADER		= ft_cub.h

RM			= rm -f

all:		init ${NAME}


ifeq ($(OS), Darwin)
init:
			@ echo "......init...MAC..."
			make -C libft
			make -C minilibx_opengl_20191021
else
init:
			@ echo "......init...LINUX..."
			make -C libft
			make -C libmlx
endif

ifeq ($(OS), Darwin)
$(NAME):	$(OBJS) $(HEADER)
			$(CC) $(FLAGS) $? $(HEADER) -Llibft -lft -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
else
			$(CC) $(FLAGS) $(OBJS) $(HEADER) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext -o $(NAME)
endif

%.o : %.c
			${CC} $(FLAGS) -c $< -o $@

clean:
			${RM} ${OBJS} ${BOBJS} *.out
			make -C libft clean
		
fclean:		clean
			$(RM) -rf $(NAME)
			make -C libft fclean


# 		!!!!!!!!	ADD FCLEAN FOR MLX          !!!!!!!!


re:			fclean all

.PHONY:		all clean fclean re

# commands
# http://rus-linux.net/nlib.php?name=/MyLDP/algol/gnu_make/gnu_make_3-79_russian_manual.html#SEC77