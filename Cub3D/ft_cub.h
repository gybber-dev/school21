#ifndef FT_CUB_H
# define FT_CUB_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx_mms_20200219/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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
}					t_set;



int					get_next_line(int fd, char **line);
t_set				ft_parser(char *file, char **map);
#endif