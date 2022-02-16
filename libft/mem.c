/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:01:54 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/16 04:28:46 by maabidal         ###   ########.fr       */
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

/*
void	foreach_in_tab(void **tab, int *sizes,  t_tab_func func, void *fix_data)
{
	int	x;
	int	y;

	x = 0;
	while (x < sizes[0])
	{
		y = 0;
		while (y < sizes[1])
		{
			(*func)(tab[x][y], x, y, fix_data);
			y++;
		}
		x++;
	}
}

void	map_tabs(void **intpur, int *sizes,  t_map_tab_func func, void **output)
{
	int	x;
	int	y;

	x = 0;
	while (x < sizes[0])
	{
		y = 0;
		while (y < sizes[1])
		{
			output[x][y] = (*func)(tab[x][y]);
			y++;
		}
		x++;
	}
}
*/
