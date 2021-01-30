cmake_minimum_required(VERSION 3.17)
project(Cub3D C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(gnl)
include_directories(libft)

add_executable(Cub3D
		errors/ft_error.c
		errors/ft_errors.h
		parser/ft_parser.c
		parser/ft_parser.h
		parser/binary_utils.c
		parser/ft_parse_file.c
		parser/ft_parse_map.c
		parser/ft_validator.c
		regexp/ft_regexp.c
		regexp/ft_regexp.h
		_config.h
		ft_cub.h
		main.c)

target_link_libraries(
		Cub3D ${CMAKE_SOURCE_DIR}/libft.a
)
