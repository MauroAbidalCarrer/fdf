/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:01:54 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/16 00:57:42 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_wf	init_dimensions(char *pathname)
{
	t_wf	wf;
	int	fd;
	char	*line;
	char 	**c_heights;

	fd = open(pathname, O_RDONLY);
	line = get_next_line(fd);
	clear_mem(&wf, sizeof(t_wf));
	c_heights = ft_split(line, ' ');
	while (c_heights[wf.sizes[0]])
		wf.sizes[0]++;
	free_tab((void **)c_heights, wf.sizes[0]);
	while (line)
	{
		wf.sizes[1]++;
		free(line);
		line = get_next_line(fd);
	}
	//free(line);?
	return (wf);
}

t_wf	set_vertex(t_wf wf, int x, int y, char *str_height)
{
	double	value;
	t_v	point;

	value = ft_atof(str_height) / 10.0;
	point.x = -(double)(x - wf.sizes[X] / 2);
	point.y = value;
	point.z = (double)(y - wf.sizes[Y] / 2);
	wf.vertices[x][y] = point;
	value = magnitude(point);
	if (value > wf.max_iso_magnitude)
	{
		wf.max_iso_magnitude = value;
		point = new_v(value, value, 0);
		point = normalized(point);
		point = mul_d(point, NEAR_PLANE);
		wf.max_per_magnitude = magnitude(point);
	}
	return (wf);
}

t_wf	fill_wf(t_wf wf, char *pathname)
{
	int	fd;
	char	*line;
	char 	**c_heights;
	int	point[2];

	fd = open(pathname, O_RDONLY);
	line = get_next_line(fd);
	point[Y] = 0;
	while (line)
	{
		c_heights = ft_split(line, ' ');
		if (c_heights == NULL)
		{
			free_tab((void **)wf.vertices, wf.sizes[0]);
			free(line);
			exit(1);
		}
		point[X] = -1;
		while (++point[X] < wf.sizes[0])
			wf = set_vertex(wf, point[X], point[Y], c_heights[point[X]]);
		free_tab((void **)c_heights, wf.sizes[0]);
		free(line);
		line = get_next_line(fd);
		point[Y]++;
	}
	return (wf);
}

t_wf	parse_file(char *pathname)
{
	t_wf	wf;

	wf = init_dimensions(pathname);
	wf.vertices = (t_v **)alloc_tab(sizeof(t_v), wf.sizes[0], wf.sizes[1]);
	if (wf.vertices == NULL)
		exit(1);
	wf = fill_wf(wf, pathname);
//printf("max height = %f\n", wf.max_height);
	return (wf);
}
/*
int	main(int ac, char **av)
{
	t_wf wf;

	wf = parse_file(av[1]);

	for (int i = 0; i < wf.sizes[1]; i++)
	{
		for (int j = 0; j < wf.sizes[0]; j++)
			printf("%f ", wf.heights[j][i]);
		printf("\n");
	}
	if (wf.heights)
		free_tab((void **)wf.heights, wf.sizes[0] - 1);
}
*/
