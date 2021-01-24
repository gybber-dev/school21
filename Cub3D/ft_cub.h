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

// delete below:

# include "_config.h"

// delete ^^^^^^



typedef struct		s_obj
{

}					t_obj;

int					get_next_line(int fd, char **line);
t_obj				ft_parser(char *file, char **map);
#endif