/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:01:54 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/14 20:16:13 by maabidal         ###   ########.fr       */
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
	while (c_heights[wf.width])
		wf.width++;
	free_tab((void **)c_heights, wf.width);
	while (line)
	{
		wf.length++;
		free(line);
		line = get_next_line(fd);
	}
	//free(line);?
	return (wf);
}

void	fill_wf(t_wf wf, char *pathname)
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
			free_tab((void **)wf.heights, wf.width);
		point[X] = -1;
		while (++point[X] < wf.width)
		{
			if (ft_atof(c_heights[point[X]]) > wf.max_height)
				wf.max_height = ft_atof(c_heights[point[X]]);
			wf.heights[point[X]][point[Y]] = ft_atof(c_heights[point[X]]);
		}
		free_tab((void **)c_heights, wf.width);
		free(line);
		line = get_next_line(fd);
		point[Y]++;
	}
	//free(line);?
}

t_wf	parse_file(char *pathname)
{
	t_wf	wf;

	wf = init_dimensions(pathname);
	wf.heights = (double **)alloc_tab(sizeof(double), wf.width, wf.length);
	if (wf.heights == NULL)
		exit(1);
	fill_wf(wf, pathname);
	return (wf);
}
/*
int	main(int ac, char **av)
{
	t_wf wf;

	wf = parse_file(av[1]);

	for (int i = 0; i < wf.length; i++)
	{
		for (int j = 0; j < wf.width; j++)
			printf("%f ", wf.heights[j][i]);
		printf("\n");
	}
	if (wf.heights)
		free_tab((void **)wf.heights, wf.width - 1);
}
*/
