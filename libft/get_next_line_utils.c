/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:29:47 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/12 23:52:38 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*r_join(char *s1, char *s2, size_t s2_len)
{
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s2_len-- > 0)
	{
		*s1 = s2[s2_len];
		s1--;
	}
	return (s1);
}

void	*free_prev(char **prev_add)
{
	free(*prev_add);
	*prev_add = NULL;
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*alloc_line(size_t len)
{
	char	*line;

	if (len == 0)
		return (NULL);
	line = malloc(sizeof(char) * (1 + len));
	if (line == NULL)
		return (NULL);
	*line = 0;
	while (len > 0)
		line[len--] = 0;
	return (line);
}

size_t	n_index(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
