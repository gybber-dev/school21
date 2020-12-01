#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H
# ifndef	BUFFER_SIZE
#  define	BUFFER_SIZE 64
# endif
#include	<unistd.h>
#include	<stdlib.h>
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2, int clear);
int			get_next_line(int fd, char **line);
void		free_mem(char **arg0, char **arg1, char **arg2);
char		*ft_strchr(const char *s, int c);
void		*ft_memmove(void *dst, const void *src, size_t len);
#endif
