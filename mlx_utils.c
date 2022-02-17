/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:38:56 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/17 21:13:09 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	vec_to_color(t_v col)
{
	int	r;
	int	g;
	int	b;

	r = ((int)col.x) << 8;
	g = ((int)col.y) << 4;
	b = (int)col.z;
	return (r | g | b);
}

void	put_pixel(t_v point, t_mlx_data mlx_data, t_v color)
{
	int	x;
	int	y;

	x = HALF_PIX_PIX_PER_SIDE + (int)point.x;
	y = HALF_PIX_PIX_PER_SIDE - (int)point.y;
	mlx_pixel_put(mlx_data.mlx, mlx_data.win, x, y, vec_to_color(color));
}

double	lerp(double a, double b, double t)
{
	return (a + (b - a) * t);
}

t_v	lerp_v(t_v a, t_v b, double t)
{
	a.x = lerp(a.x, b.x, t); 
	a.y = lerp(a.y, b.y, t); 
	return (a);
}

void	draw_line(t_point_n_col point, t_point_n_col end, t_mlx_data mlx_data)
{
	double	nb_steps;
	double	i;
	t_v	color;

	nb_steps = fmax(fabs(end.point.x - point.point.x), fabs(end.point.y - point.point.y));
	put_pixel(point.point, mlx_data, point.col);
	i = 1;
	while (i < nb_steps)
	{
		color = lerp_v(point.col, end.col, i / nb_steps);
		put_pixel(lerp_v(point.point, end.point, i / nb_steps), mlx_data, color);
		i += 1;
	}
}

t_mlx_data	init_mlx()
{
	t_mlx_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, PIX_PER_SIDE, PIX_PER_SIDE, "fdf");
	return (data);
}
