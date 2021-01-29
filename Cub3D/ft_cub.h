#ifndef FT_CUB_H
# define FT_CUB_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx_mms_20200219/mlx.h"
# include "errors/ft_errors.h"
# include "regexp/ft_regexp.h"
# include "parser/ft_parser.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

#define SAVE_FLAG "--save"

// delete below:

# include "_config.h"

// delete ^^^^^^

typedef struct		s_win
{
	int				res1;
	int				res2;
}					t_win;

typedef struct		s_skin
{
	int				fl_col;
	int				ce_col;
	char			*no_ski;
	char			*so_ski;
	char			*we_ski;
	char			*ea_ski;
	char			*fl_ski;
	char			*ce_ski;
	char			*sprite_ski;
}					t_skin;

typedef struct		s_map
{
	char			**c_map;
	int				ismalloced;
}					t_map;

typedef struct		s_set
{
	t_win			win;
	t_skin			skin;
	t_map			map;
}					t_set;



t_set				ft_parser(char *file, char **map);
void				ft_parse_map(char *line, t_set *set);
void				set_mem_for_map(char *str, t_set *set);

#endif