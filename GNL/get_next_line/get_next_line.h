#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H
# ifndef	BUFFER_SIZE
#  define	BUFFER_SIZE 10
# endif
#include	<unistd.h>
#include	<stdlib.h>
// #include	<stdio.h>
int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);
void		free_mem(char **mem);
char		*ft_strjoin(char *s1, char *s2);
#endif
