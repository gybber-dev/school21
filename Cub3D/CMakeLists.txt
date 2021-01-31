cmake_minimum_required(VERSION 3.17)
project(Cub3D C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_subdirectory(./libft)

message(HELLO ${CMAKE_SOURCE_DIR})



add_executable(Cub3D
#		libft/ft_atoi.c
#		libft/ft_free.c
#		libft/ft_isdigit.c
#		libft/ft_putchar_fd.c
#		libft/ft_putstr_fd.c
#		libft/ft_strtrim.c
#		libft/ft_strdup.c
#		libft/ft_strchr.c
#		libft/ft_strjoin.c
#		libft/ft_strlen.c
#		libft/ft_strncmp.c
#		libft/ft_substr.c
#		libft/ft_memcpy.c
#		libft/ft_memmove.c
#		libft/ft_bzero.c
#		libft/ft_strlcat.c
		errors/ft_error.c
		parser/ft_parser.c
		parser/binary_utils.c
		parser/ft_parse_file.c
		parser/ft_parse_map.c
		parser/ft_validator.c
		regexp/ft_regexp.c
		regexp/ft_regexp.h
		_config.h
		ft_cub.h
		main.c)


target_link_libraries(Cub3D
#		Cub3D ${CMAKE_SOURCE_DIR}/libft/libft.a
		libft
#		${CMAKE_SOURCE_DIR}/minilibx_mms/libmlx.dylib
#		"-framework OpenGL"
#		"-framework AppKit"
)
