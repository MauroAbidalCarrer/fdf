/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:17:14 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/16 03:59:08 by maabidal         ###   ########.fr       */
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
			sp[x][y].z = dot(matrix.k, wf.vertices[x][y]);
		}
	}
}

#include <time.h>

void	apply_perspective_transformation(t_wf wf, t_matrix matrix, t_display_data display)
{
	int		x;
	int		y;
	double calibration;
	t_v		point;


/* here, do your time-consuming job */

	calibration = (NEAR_PLANE / wf.max_per_magnitude) * PIX_PER_SIDE;
	//printf("wf.max_per_magnitude = %f\n", wf.max_iso_magnitude);
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
			point.z += 1.0 / display.zoom + wf.max_iso_magnitude;//wf.max_per_magnitude;
			point = normalized(point);
			point = mul_d(point, calibration);
			display.sp[x][y] = point;
		}
	}
}

void	draw_wf(t_all_data *data)
{
	t_matrix	matrix;

	mlx_clear_window(data->mlx->mlx, data->mlx->win);
clock_t begin = clock();
	if (data->display->display_mode == ISO_MODE)
	{
		mk_isometric_matrix(*data->wf, *data->display, &matrix);
		apply_isometric_transformation(*data->wf, matrix, data->display->sp);
	}
	else
	{
		mk_perspective_matrix(*data->display, &matrix);
		apply_perspective_transformation(*data->wf, matrix, *data->display);
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//printf("time taken to apply the transformation= %f\n", time_spent);
	}
begin = clock();
	draw_segments(data->display->sp,  *data->wf, *data->mlx);
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//printf("time taken to draw the segments = %f\n", time_spent);
}
