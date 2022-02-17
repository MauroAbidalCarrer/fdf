/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:17:14 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/17 17:16:12 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_segments(t_v **sp, t_wf  wf, t_mlx_data mlx_data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < wf.sizes[X])
	{
		y = -1;
		while (++y < wf.sizes[Y])
		{
			if (x < wf.sizes[0] - 1)
				draw_line(sp[x][y], sp[x + 1][y], mlx_data);
			if (y < wf.sizes[1] - 1)
				draw_line(sp[x][y], sp[x][y + 1], mlx_data);
		}
	}
}

void	apply_isometric_transformation(t_wf wf, t_matrix matrix, t_v **sp)
{
	int	x;
	int	y;

	x = -1;
	while (++x < wf.sizes[0])
	{
		y = -1;
		while (++y < wf.sizes[1])
		{
			sp[x][y].x = dot(matrix.i, wf.vertices[x][y]);
			sp[x][y].y = dot(matrix.j, wf.vertices[x][y]);
		}
	}
}

void	apply_perspective_transformation(t_wf wf, t_matrix matrix, t_display_data display)
{
	int		x;
	int		y;
	double calibration;
	t_v		point;
	double	offset;

	offset = wf.max_iso_magnitude + NEAR_PER_PLANE + 1;
	calibration = PIX_PER_SIDE;
	x = -1;
	while (++x < wf.sizes[0])
	{
		y = -1;
		while (++y < wf.sizes[1])
		{
			point = display.sp[x][y];
			point = mul_d(matrix.i, wf.vertices[x][y].x);
			point = sum(point, mul_d(matrix.j, wf.vertices[x][y].y));
			point = sum(point, mul_d(matrix.k, wf.vertices[x][y].z));
			point.x = -point.x;
			point.z += offset;
			point = div_d(point, point.z);
			point = div_d(point, wf.max_per_magnitude);
			point = mul_d(point, NEAR_PER_PLANE * HALF_PIX_PIX_PER_SIDE * display.zoom);
			display.sp[x][y] = point;
		}
	}
}

void	draw_wf(t_all_data *data)
{
	t_matrix	matrix;

	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	if (data->display->display_mode == ISO_MODE)
	{
		mk_isometric_matrix(*data->wf, *data->display, &matrix);
		apply_isometric_transformation(*data->wf, matrix, data->display->sp);
	}
	else
	{
		mk_perspective_matrix(*data->display, &matrix);
		apply_perspective_transformation(*data->wf, matrix, *data->display);
	}
	draw_segments(data->display->sp,  *data->wf, *data->mlx);
}
