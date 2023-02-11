#include "get_next_line_bonus.h"
#include <stdio.h>

t_list	*which_file(t_list *head, int fd)
{
	t_list	*curr;

	curr = head;
	if (curr->nbr == (fd + 1))
		return (curr);
	while (curr->nbr)
	{
		if (!curr->next)
		{
			curr->next = malloc(sizeof(t_list));
			curr->next->prev = curr;
			curr->next->next = NULL;
			curr->next->content = NULL;
			curr->next->nbr = 0;
		}
		curr = curr->next;
		if (curr->nbr == (fd + 1))
			return (curr);
	}
	curr->nbr = (fd + 1);
	return (curr);
}

char	*get_to_second_line(char *content)
{
	char	*ret;
	int		i1;
	int		i2;

	i1 = 0;
	while (content[i1] && content[i1] != '\n')
		i1++;
	if (!content[i1])
	{
		free(content);
		return (NULL);
	}
	ret = malloc(ft_strlen(content) - i1);
	if (!ret)
		return (NULL);
	i2 = 0;
	i1++;
	while (content[i1])
		ret[i2++] = content[i1++];
	ret[i2] = '\0';
	free(content);
	return (ret);
}

char	*get_first_line(const char *content)
{
	int		i;
	char	*ret;

	i = 0;
	if (!content[i])
		return (NULL);
	while(content[i] && content[i] != '\n')
		i++;
	ret = malloc(i + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		ret[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

void	read_line(t_list *curr)
{
	char	*concat;
	int		bytes_readed;

	concat = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!concat)
		return ;
	bytes_readed = 1;
	while (bytes_readed != 0 && !ft_strchr(curr->content, '\n'))
	{
		bytes_readed = read((curr->nbr - 1), concat, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(concat);
			curr->content = malloc(1);
			(curr->content)[0] = '\0';
			return ;
		}
		concat[bytes_readed] = '\0';
		curr->content = ft_strjoin(curr->content, concat);
	}
	free(concat);
}
char	*get_next_line(int	fd)
{
	char			*ret;
	static t_list	*head;
	t_list			*curr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
		head = malloc(sizeof(t_list));
	curr = which_file(head, fd);
	read_line(curr);
	ret = get_first_line(curr->content);
	curr->content = get_to_second_line(curr->content);
	return (ret);
}
