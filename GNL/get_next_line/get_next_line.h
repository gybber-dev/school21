#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H
# define	BUFFER_SIZE 10
#include	<unistd.h>
#include	<stdlib.h>
int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		ft_bzero(void *b, size_t len);
#endif
