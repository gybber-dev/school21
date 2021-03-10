cmake_minimum_required(VERSION 3.17)
project(Cub3D C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_subdirectory(./libft)

add_executable(Cub3D
		ft_error.c
		parser/ft_parser.c
		parser/ft_parse_head.c
		parser/ft_validator.c
		parser/ft_parse_head.c
		game/game.c
		game/dda.c
		game/moving.c
		game/sprite.c
		game/screenshot.c
		ft_cub.h
		utils_vector.c
		main.c
		utils_mlx.c)

if (APPLE)
	target_link_libraries(Cub3D
	#		Cub3D ${CMAKE_SOURCE_DIR}/libft/libft.a
			libft
			"-framework OpenGL"
			"-framework AppKit"
			${CMAKE_SOURCE_DIR}/libmlx_mac/libmlx.a
			)
endif(APPLE)
if (UNIX AND NOT APPLE)
	target_link_libraries(Cub3D
			#		Cub3D ${CMAKE_SOURCE_DIR}/libft/libft.a
			libft
			${CMAKE_SOURCE_DIR}/libmlx/libmlx.a
			"-lX11"
			"-lz"
			"-lm"
			"-lXext"
	)
endif(UNIX AND NOT APPLE)