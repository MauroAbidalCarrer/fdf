/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:01:54 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/14 19:55:42 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clear_mem(void *bytes, int nb_bytes)
{
	while (nb_bytes-- > 0)
		((unsigned char *) bytes)[nb_bytes] = 0;
}

void	free_tab(void **ptr, int i)
{
	while (i >= 0)
		free(ptr[i--]);
	free(ptr);
}

void	**alloc_tab(size_t element_size, int x, int y)
{
	void	**ptr;

	ptr = malloc(sizeof(void *) * x);
	if (ptr == NULL)
		return (NULL);
	while (--x >= 0)
	{
		ptr[x] = malloc(element_size * y);
		if (ptr[x] == NULL)
		{
			free_tab(ptr, x);
			return (NULL);
		}
	}
	return (ptr);
}
