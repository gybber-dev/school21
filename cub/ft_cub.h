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


# ifdef __linux__
#  include "libmlx/mlx.h"
/*
** KEYCODES:
*/
#  define OS "LINUX"
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define C 99
#  define UP 65362
#  define LEFT 65361
#  define DOWN 65364
#  define RIGHT 65363
#  define SPACE 32
#  define LMOUSE none
#  define RMOUSE none
# else
#  include "minilibx_opengl_20191021/mlx.h"
#  define OS "MAC"
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define C 8
#  define UP 126
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define SPACE 49
#  define LMOUSE 0
#  define RMOUSE 0
# endif

#  define ESC_BIT 0
#  define W_BIT 1
#  define A_BIT 2
#  define S_BIT 3
#  define D_BIT 4
#  define C_BIT 12
#  define UP_BIT 5
#  define LEFT_BIT 6
#  define DOWN_BIT 7
#  define RIGHT_BIT 8
#  define SPACE_BIT 9
#  define LMOUSE_BIT 10
#  define RMOUSE_BIT 11

/*
** ERROR MESSAGES:
*/

# define SCALE 30
# define STEP 0.05
# define HOR_SIT 2.1
# define HOR 2
# define HOR_JUMP 1.5
# define ANGLE_STEP 0.02
# define ZERO_VAL 0.0001
# define PLANE_W 0.7
# define RAYS_NUM 40
# define ERR_READ_FILE 1001
# define NOT_VALID_HEAD_0 1010
# define NOT_VALID_HEAD_1 1011
# define NOT_VALID_HEAD_2 1012
# define NOT_VALID_LINE 1013
# define NOT_VALID_TEXTURE 1021
# define PARALLEL_VECTORS_NOT_CROSS 1022

# define MAP_SYMBOLS "10 2NSWE"
# define SAVE "--save"

// delete below:

# include "_config.h"

// delete ^^^^^^

typedef struct		s_pix
{
	int				x;
	int				y;
}					t_pix;

typedef struct		s_fpix
{
	double 			x;
	double 			y;
}					t_fpix;

typedef struct		s_sprite
{
	int				num;
	t_fpix			pos;
	t_fpix			plane;
	t_pix			wall;
	t_pix			strip;
	struct s_sprite	*next;
	double			h;
	double			dist;
	int				side;

}					t_sprite;



typedef struct		s_spr
{
	t_fpix			pos;
	t_fpix			xlim;
	t_fpix			start;
	t_fpix			end;
	t_fpix			proj_c;
	double			dist;
	double			perp;
	double			height;
}					t_spr;


typedef struct		s_sl
{
	t_spr			sprite;
	struct s_sl 	*next;
}					t_sl;

typedef struct		s_img
{
	t_pix			res;
	void			*img;
	char			*addr;
	int				bpp;
	int				len;
	int				endian;
}					t_img;

typedef struct		s_msgs
{
	int 			code;
	char 			*text;
}					t_msgs;



typedef struct		s_ray
{
	int				x;
	int				side;
	t_fpix			dir;
	double			dist;
	double			perp;
	t_fpix			cross;
	t_sprite		*slist;
}					t_ray;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	t_img			img1;
	t_img			img;
	t_img 			skins[5];
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
	int				isparsed;
}					t_map;


typedef struct		s_player
{
	t_fpix			pos;
	int				move;
	t_fpix			dir;
	t_pix			step;
	t_fpix			plane;
	double			hor;
}					t_player;

typedef struct		s_set
{
	int				contents;
	t_win			win;
	t_skin			skin;
	t_map			map;
	t_player		player;
	t_sl			*sl;
	int				save;
	char			*tmp;
	int				os;
}					t_set;

void 				ft_parser(char *file_name, t_set *set);
void				ft_parse_map(char *line, t_set *set);
void				parse_resolution(t_set *set, char *line);
void				set_mem_for_map(char *str, t_set *set);
int					ft_validate_data(t_set *set);
void				ft_error(t_set *set, int code);
int					read_file(t_set *set, int fd, char **file);
int					get_b(int trgb);
int					get_g(int trgb);
int					get_r(int trgb);
int					get_t(int trgb);
int					create_trgb(int t, int r, int g, int b);
int					is_map(char *str);
void				my_mlx_pixel_put(t_set *set, int x, int y, int color);
int					display_img(t_set *set);
void				draw_map(t_set *set);
void				run_game(t_set *set);
void				update_pos(t_set *set);
int					key_hook_up(int keycode, t_set *set);
int					key_hook_press(int keycode, t_set *set);
double				v_len(t_fpix v);
double				v_dist(t_fpix d1, t_fpix d2);
t_fpix				v_set(double val_x, double val_y);
void				v_scale(t_fpix *v, double k);
t_fpix				v_sub(t_fpix v1, t_fpix v2);
t_fpix				v_sum_num(t_fpix src, double x, double y);
t_fpix				v_mult_num(t_fpix vec, double x, double y);
double				v_mult(t_fpix v1, t_fpix v2);
void				screen_image(t_set *set);
void				auto_clear(t_set *set);
int					finish_programm(t_set *set);
#endif