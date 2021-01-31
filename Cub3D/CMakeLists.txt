cmake_minimum_required(VERSION 3.17)
project(Cub3D C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_subdirectory(./libft)

add_executable(Cub3D
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
		${CMAKE_SOURCE_DIR}/minilibx_opengl_20191021/libmlx.a
		"-framework OpenGL"
		"-framework AppKit"
)
