/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:38:56 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/14 20:15:42 by maabidal         ###   ########.fr       */
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
	mlx_pixel_put(mlx_data.mlx_ptr, mlx_data.win_ptr, x, y, COLOR);
}

void	draw_line(t_v point, t_v end, t_mlx_data mlx_data)
{
	t_v dir;

	dir = normalized(dif(end, point));
	put_pixel(point, mlx_data);
	while ((int)point.x != (int)end.x || (int)point.y != (int)end.y)
	{
		point = sum(point, dir);
		put_pixel(point, mlx_data);
	}
}

