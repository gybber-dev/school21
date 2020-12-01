#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H
# ifndef	BUFFER_SIZE
#  define	BUFFER_SIZE 1
# endif
#include	<unistd.h>
#include	<stdlib.h>
int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);
void		free_mem(char **arg0, char **arg1);
char		*ft_strjoin(char *s1, char *s2, char *clear);
#endif
