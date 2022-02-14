/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:01:54 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/13 22:11:32 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_wf(t_wf wf, int x, int exit_status)
{
	while (--x >= 0)
		free(wf.heights[x]);
	free(wf.heights);
	exit(exit_status);
}

t_wf	alloc_heights(t_wf wf)
{
	int	x;

	wf.heights = malloc(sizeof(double *) * wf.width);
	if (wf.heights == NULL)
		exit(1);
	x = 0;
	while (x < wf.width)
	{
		wf.heights[x] = malloc(sizeof(double) * wf.length);
		if (wf.heights[x] == NULL)
			free_wf(wf, x, 1);
		x++;
	}
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
			free_wf(wf, wf.width, 1);
		point[X] = -1;
		while (++point[X] < wf.width)
		{
			if (ft_atof(c_heights[point[X]]) > wf.max_height)
				wf.max_height = ft_atof(c_heights[point[X]]);
			wf.heights[point[X]][point[Y]] = ft_atof(c_heights[point[X]]);
		}
		free_strings(c_heights, wf.width);
		free(line);
		line = get_next_line(fd);
		point[Y]++;
	}
	free(line);
}

t_wf	parse_file(char *pathname)
{
	t_wf	wf;
	int	fd;
	char	*line;
	char 	**c_heights;

	fd = open(pathname, O_RDONLY);
	line = get_next_line(fd);
	ft_clear(&wf, sizeof(t_wf));
	c_heights = ft_split(line, ' ');
	while (c_heights[wf.width])
		wf.width++;
	free_strings(c_heights, wf.width);
	while (line)
	{
		wf.length++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	wf = alloc_heights(wf);
	fill_wf(wf, pathname);
	return (wf);
}

void	print_wf(t_wf wf)
{
	for (int i = 0; i < wf.length; i++)
	{
		for (int j = 0; j < wf.width; j++)
			printf("%f ", wf.heights[j][i]);
		printf("\n");
	}
}

int	main(int ac, char **av)
{
	t_wf wf;

	wf = parse_file(av[1]);
	print_wf(wf);
	free_wf(wf, wf.width, 0);
}
