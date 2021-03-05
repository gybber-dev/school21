#include "../ft_cub.h"

//void			parse_resolution(t_set *set, char *line)
//{
//	if (set->win.img1.res.x != 0 || set->win.img1.res.y != 0)
//		ft_error(set, NOT_VALID_HEAD_1);
//	line += 2;
//	while(*line == ' ')
//		line++;
//	if (ft_isdigit(*line))
//		set->win.img1.res.x = ft_atoi(line);
//	while (ft_isdigit(*line))
//		line++;
//	while(*line == ' ' || *line == ',')
//		line++;
//	if (ft_isdigit(*line))
//		set->win.img1.res.y = ft_atoi(line);
//	while(ft_isdigit(*line))
//		line++;
//	while(*line == ' ' || *line == ',')
//		line++;
//	if (*line != 0 ||
//			set->win.img1.res.x == 0 || set->win.img1.res.y == 0)
//		ft_error(set, NOT_VALID_HEAD_2);
//}