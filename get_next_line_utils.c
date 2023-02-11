/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:46:07 by yumamur           #+#    #+#             */
/*   Updated: 2023/02/11 17:15:51 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;
	int		i;

	i = count * size;
	pt = malloc(i);
	while (i)
	{
		((unsigned char *)pt)[i] = 0;
		i--;
	}
	return (pt);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i1;
	int		i2;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i1 = -1;
	i2 = 0;
	while (s1[++i1])
		str[i1] = s1[i1];
	while (s2[i2])
		str[i1++] = s2[i2++];
	str[i1] = '\0';
	free(s1);
	return (str);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char )c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
