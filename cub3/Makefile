NAME		= cub3D

SRCS	= \
			parser/ft_parser.c \
			parser/ft_parser_utils.c \
			parser/ft_count_sprites.c \
			parser/ft_parse_head.c \
			parser/ft_validator.c \
			game/game.c \
			game/sprite.c \
			game/dda.c \
			game/moving.c \
			game/screenshot.c \
			utils_vector.c \
			utils_mlx.c \
			ft_error.c \
			main.c \

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

all:		init ${NAME} $(HEADER)

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

norm:
			norminette $(SRCS)
			norminette $(HEADER)
			norminette libft/*.c

.PHONY:		all clean fclean re norm
