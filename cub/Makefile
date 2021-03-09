NAME		= cub3D

SRCS	= \
			errors/ft_error.c \
			regexp/ft_regexp.c \
			parser/ft_parser.c \
			parser/ft_parse_head.c \
			parser/ft_validator.c \
			main.c \
			utils0.c \
			window/window.c \
			window/player.c \
			window/map.c \
			window/moving.c \
			window/vector_utils.c \
			window/screenshot.c \

OBJS		= $(patsubst %.c, %.o, $(SRCS))
OS			:= $(shell uname)

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
HEADER		= ft_cub.h
RM			= rm -f
ifeq ($(OS), Darwin)
LIB_FLAGS	= -Llibmlx_mac -lmlx -framework OpenGL -framework AppKit
LIB_DIR		= libmlx_mac
else
LIB_FLAGS	= -Llibmlx -lmlx -lX11 -lm -lXext -lbsd
LIB_DIR		= libmlx
endif

all:		init ${NAME}

init:
			@ echo $(OS)
			make -C libft
			make -C $(LIB_DIR)

$(NAME):	$(OBJS) $(HEADER)
			$(CC) $(FLAGS) ${OBJS} -Llibft -lft $(LIB_FLAGS) -o $(NAME)

%.o : %.c
			${CC} $(FLAGS) -c $< -o $@

clean:
			${RM} ${OBJS} ${BOBJS} *.out
			make -C libft clean
			make -C $(LIB_DIR) clean

fclean:		clean
			$(RM) -rf $(NAME)
			make -C libft fclean
			make -C $(LIB_DIR) clean

re:			fclean all

.PHONY:		all clean fclean re

# commands
# http://rus-linux.net/nlib.php?name=/MyLDP/algol/gnu_make/gnu_make_3-79_russian_manual.html#SEC77