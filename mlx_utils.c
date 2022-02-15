/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:38:56 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/15 15:22:16 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_pixel(t_v v, t_mlx_data mlx_data)
{
	int	x;
	int	y;

	v.x = floor(v.x);
	v.y = floor(v.y);
	x = PIX_PER_SIDE / 2 + (int)v.x;
	y = PIX_PER_SIDE / 2 - (int)v.y;
	mlx_pixel_put(mlx_data.mlx, mlx_data.win, x, y, COLOR);
}

void	draw_line(t_v point, t_v end, t_mlx_data mlx_data)
{
	t_v dir;
	double	mag;

	dir = dif(end, point);
	mag = magnitude(dir);
	dir = div_d(dir, mag);
	put_pixel(point, mlx_data);
	/*
	printf("drawing line between\n");
	print_v2(point);
	print_v2(end);
	printf("\n");
	*/
	//while (floor(point.x) != floor(end.x) || floor(point.y) != floor(end.y))
	while (((int)point.x != (int)end.x || (int)point.y != (int)end.y) && mag > 1)
	{
		point = sum(point, dir);
		if (point.x > (double)PIX_PER_SIDE / 2.0 || point.x < -(double)PIX_PER_SIDE / 2.0 ||
			point.y > (double)PIX_PER_SIDE / 2.0 || point.y < -(double)PIX_PER_SIDE / 2.0)
		{/*print_v2(point);printf("outsidie of bounds\n");*/}
		else
			put_pixel(point, mlx_data);
		mag -= 1.0;
	}
}

t_mlx_data	init_mlx()
{
	t_mlx_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, PIX_PER_SIDE, PIX_PER_SIDE, "oui");
	return (data);
}
