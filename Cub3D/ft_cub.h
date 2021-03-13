/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:08:39 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 21:08:44 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>

/*
** KEYCODES:
*/

# ifdef __linux__
#  include "libmlx/mlx.h"
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
# else
#  include "libmlx_mac/mlx.h"
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
# define W_BIT 1
# define A_BIT 2
# define S_BIT 3
# define D_BIT 4
# define C_BIT 12
# define UP_BIT 5
# define LEFT_BIT 6
# define DOWN_BIT 7
# define RIGHT_BIT 8
# define SPACE_BIT 9
# define LMOUSE_BIT 10
# define RMOUSE_BIT 11

/*
** ERROR MESSAGES:
*/

# define STEP 0.2
# define HOR_SIT 2.1
# define HOR 2
# define BCKGRND 0xFFFFFF
# define ANGLE_STEP 0.05
# define ZERO_VAL 0.0001
# define PLANE_W 0.7
# define ERR_READ_FILE 1001
# define ERR_FEW_DATA 1002
# define ERR_PLAYERS 1003
# define ERR_HEAD_0 1010
# define ERR_HEAD_1 1011
# define ERR_HEAD_2 1012
# define ERR_LINE 1013
# define ERR_MAP 1030
# define SAVE "--save"

typedef struct		s_pix
{
	int				x;
	int				y;
}					t_pix;

typedef struct		s_fpix
{
	double			x;
	double			y;
}					t_fpix;

typedef struct		s_spr
{
	t_fpix			pos;
	t_fpix			xlim;
	t_fpix			start;
	t_fpix			end;
	t_fpix			proj_c;
	double			dist;
	double			perp;
	double			h;
}					t_spr;

typedef struct		s_sl
{
	t_spr			spr;
	struct s_sl		*next;
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

typedef struct		s_msg
{
	int				code;
	char			*text;
}					t_msg;

typedef struct		s_ray
{
	int				x;
	int				side;
	t_fpix			dir;
	double			dist;
	double			perp;
	double			h;
	t_fpix			cross;
}					t_ray;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_img			skins[5];
}					t_win;

typedef struct		s_skin
{
	int				fl_col;
	int				ce_col;
	char			*no_ski;
	char			*so_ski;
	char			*we_ski;
	char			*ea_ski;
	char			*spr_ski;
}					t_skin;

typedef struct		s_map
{
	char			**c_map;
	int				lines;
	int				player_counter;
	char			player_dir;
	t_fpix			pos;
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
	t_win			win;
	t_skin			skin;
	t_map			map;
	t_player		player;
	t_sl			*sl;
	int				save;
	char			*tmp;
	int				os;
}					t_set;

void				ft_parser(char *file_name, t_set *set);
void				ft_parse_map(char *line, t_set *set);
int					ft_parse_head(char *line, t_set *set);
int					ft_validate_data(t_set *set);
void				ft_error(t_set *set, int code);
void				my_mlx_pixel_put(t_set *set, int x, int y, int color);
void				write_addr(t_img *img);
int					get_clr(t_img *img, int x, int y);
void				run_game(t_set *set);
void				add_sprite(t_set *set, t_ray *ray, t_pix map);
void				draw_sprites(t_set *set);
t_fpix				prj_to_vec(t_fpix m, t_fpix n, t_fpix d0, t_fpix dot);
void				update_pos(t_set *set);
void				drop_rays(t_set *set);
int					key_hook_up(int keycode, t_set *set);
int					key_hook_press(int keycode, t_set *set);
double				v_len(t_fpix v);
double				v_dist(t_fpix d1, t_fpix d2);
t_fpix				v_set(double val_x, double val_y);
t_fpix				v_sub(t_fpix v1, t_fpix v2);
void				screen_image(t_set *set);
void				auto_clear(t_set *set);
int					finish_program(t_set *set);
#endif
