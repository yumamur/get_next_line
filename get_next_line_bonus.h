#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
    char			*content;
	int				nbr;
    struct s_list	*next;
	struct s_list	*prev;
}					t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
int		ft_strchr(char *str, int c);	
size_t	ft_strlen(const char *str);
# endif
