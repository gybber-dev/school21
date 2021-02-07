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
# include <math.h>
# include "minilibx_opengl_20191021/mlx.h"

/*
** KEYCODES:
*/

# ifdef __linux__
#  define OS "LINUX"
#  define ESC 53
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define UP 65362
#  define LEFT 65361
#  define DOWN 65364
#  define RIGHT 65363
#  define SPACE 32
#  define LMOUSE none
#  define RMOUSE none
# else
#  define OS "MAC"
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define UP 126
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define SPACE 49
#  define LMOUSE 0
#  define RMOUSE 0
# endif

/*
** ERROR MESSAGES:
*/

# define SCALE 30
# define STEP 0.3
# define RAY_STEP 3
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
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
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

typedef struct		s_pix
{
	int				x;
	int				y;
}					t_pix;
typedef struct		s_fpix
{
	float			x;
	float			y;
}					t_fpix;


typedef struct		s_player
{
	float			angle;
	t_fpix			pos;
	int				w;
	int				a;
	int				d;
	int				s;
}					t_player;

typedef struct		s_set
{
	t_win			win;
	t_skin			skin;
	t_map			map;
	t_player		player;
}					t_set;

void 				ft_parser(char *file_name, t_set *set);
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
void				my_mlx_pixel_put(t_set *set, int x, int y, int color);
void				set_player(t_set *set);
void				draw_map(t_set *set);
void				run_game(t_set *set);

#endif