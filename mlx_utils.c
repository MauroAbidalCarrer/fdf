/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:38:56 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/17 17:18:47 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_pixel(t_v v, t_mlx_data mlx_data)
{
	int	x;
	int	y;

	x = HALF_PIX_PIX_PER_SIDE + (int)v.x;
	y = HALF_PIX_PIX_PER_SIDE - (int)v.y;
	mlx_pixel_put(mlx_data.mlx, mlx_data.win, x, y, COLOR);
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

void	draw_line(t_v point, t_v end, t_mlx_data mlx_data)
{
	double	nb_steps;
	double	i;

	nb_steps = fmax(fabs(end.x - point.x), fabs(end.y - point.y));
	put_pixel(point, mlx_data);
	i = 1;
	while (i < nb_steps)
	{
		put_pixel(lerp_v(point, end, i / nb_steps), mlx_data);
		i += 1.5;
	}
}

t_mlx_data	init_mlx()
{
	t_mlx_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, PIX_PER_SIDE, PIX_PER_SIDE, "fdf");
	return (data);
}
