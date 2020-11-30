#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H
# ifndef	BUFFER_SIZE
#  define	BUFFER_SIZE 10
# endif
#include	<unistd.h>
#include	<stdlib.h>
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2, int clear);
// int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *s, int c);
void		*ft_memmove(void *dst, const void *src, size_t len);
#endif
