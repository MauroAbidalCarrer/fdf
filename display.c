/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disply.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:17:14 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/15 21:35:10 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_segments(t_v **sp, t_wf  wf, t_mlx_data mlx_data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < wf.width)
	{
		y = -1;
		while (++y < wf.length)
		{
			if (x < wf.width - 1)
				draw_line(sp[x][y], sp[x + 1][y], mlx_data);
			if (y < wf.length - 1)
				draw_line(sp[x][y], sp[x][y + 1], mlx_data);
		}
	}
}

void	apply_isometric_matrix(t_wf wf, t_matrix matrix, t_v **sp)
{
	int	x;
	int	y;
	t_v	point;

	x = -1;
	while (++x < wf.width)
	{
		y = -1;
		while (++y < wf.length)
		{
			point = new_v(-(double)(x - wf.width / 2), wf.heights[x][y], (double)(y - wf.length / 2));
			sp[x][y].x = dot(matrix.i, point);
			sp[x][y].y = dot(matrix.j, point);
//printf("point = (%f, %f, %f), upward = (%f, %f, %f), dot(upward, point) = %f\n", point.x, point.y, point.z, upward.x, upward.y, upward.z, dot(upward, point));
		}
	}
}

void	draw_wf(t_all_data *data)
{
	t_matrix	matrix;

	if (data->display->is_processing == 1)
		return ;
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	data->display->is_processing = 1;
	if (data->display->display_mode == ISO_MODE)
	{
		mk_isometric_matrix(*data->wf, *data->display, &matrix);
		apply_isometric_matrix(*data->wf, matrix, data->display->sp);
	}
	else
	{

	}
	draw_segments(data->display->sp,  *data->wf, *data->mlx);
	data->display->is_processing = 0;
}
