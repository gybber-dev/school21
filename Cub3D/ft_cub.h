#ifndef FT_CUB_H
# define FT_CUB_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx_mms_20200219/mlx.h"
# include "errors/ft_errors.h"
# include "regexp/ft_regexp.h"

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



typedef struct		s_set
{
	t_win			win;
	t_skin			skin;
	char			**map;
}					t_set;



int					read_file(int fd, char **file);
t_set				ft_parser(char *file, char **map);
#endif