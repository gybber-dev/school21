#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "../libft/libft.h"
# include "../ft_cub.h"

# define MAP_SYMBOLS "10 2NSWE"

int		read_file(int fd, char **file);
int		get_b(int trgb);
int		get_g(int trgb);
int		get_r(int trgb);
int		get_t(int trgb);
int		create_trgb(int t, int r, int g, int b);
int		is_map(char *str);

#endif