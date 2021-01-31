#ifndef FT_CUB_H
# define FT_CUB_H
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include "regexp/ft_regexp.h"

# include <stdio.h> // for perror
# include <string.h> // for strerror
# include <errno.h> // for errno
# include <stdlib.h> // for exit
# include "minilibx_mms/mlx.h"

/*
** ERROR MESSAGES:
*/

# define ERR_READ_FILE 1001
# define NOT_VALID_HEAD_0 1011

# define MAP_SYMBOLS "10 2NSWE"

# define SAVE_FLAG "--save"

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
	int				contents;
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
int					ft_validate_data(t_set *set);
void				ft_error(int code);
int					read_file(int fd, char **file);
int					get_b(int trgb);
int					get_g(int trgb);
int					get_r(int trgb);
int					get_t(int trgb);
int					create_trgb(int t, int r, int g, int b);
int					is_map(char *str);
#endif