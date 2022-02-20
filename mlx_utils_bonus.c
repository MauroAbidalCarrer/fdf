/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:38:56 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/20 19:00:36 by maabidal         ###   ########.fr       */
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

t_v	lerp_v(t_v a, t_v b, double t)
{
	a.x = (a.x + (b.x - a.x) * t);
	a.y = (a.y + (b.y - a.y) * t);
	a.z = (a.z + (b.z - a.z) * t);
	return (a);
}

void	draw_line(t_point_n_col point, t_point_n_col end, t_mlx_data mlx_data)
{
	double	nb_steps;
	double	i;
	t_v		color;
	t_v		c_point;

	nb_steps = fabs(end.point.x - point.point.x);
	nb_steps = fmax(nb_steps, fabs(end.point.y - point.point.y));
	put_pixel(point.point, mlx_data, point.col);
	i = 1;
	while (i < nb_steps)
	{
		color = lerp_v(point.col, end.col, i / nb_steps);
		c_point = lerp_v(point.point, end.point, i / nb_steps);
		put_pixel(c_point, mlx_data, color);
		i += 1;
	}
}
