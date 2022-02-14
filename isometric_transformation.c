/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_transformation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:53:03 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/14 17:06:37 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_line(t_v point, t_v end, t_mlx_data)
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

void	draw_segments(t_v **sp, t_mlx_data mlx_data)
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
				draw_line(sp[x][y], sp[x + 1][y]);
			if (y < wf.width)
				draw_line(sp[x][y], sp[x][y + 1]);
		}
	}
}

void	apply_isometric_matrix(t_wf wf, t_v upward, t_v sideway, t_v **sp)
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
			point = new_t((double)x, wf.heights[x][y], (double)y);
			sp[x][y].x = dot(sideway, point);
			sp[x][y].y = dot(upward, point);
		}
	}
}

void	mk_isometric_matrix(t_wf wf, t_v cam_rot, t_v *upward, t_v *sideway)
{
	t_v	max_point;
	double	calibration;

//create to_screen matrix
	*upward = angles_to_vector(sum(orientation, new_v(90, 0, 0)));
	*sideway = angles_to_vector(new_v(0, orientation.y - 90, 0));
//calibrate
	calibration = (double)PIX_PER_SIDE;
	max_point = new_v((double)wf.width, (double)wf.length, wf.max_height);
	calibration /= magnitude(max_point);
	calibration *= FRACTION_OF_SCREEN;
	*upward = mul_d(*upward, calibration);
	*sideway = mul_d(*sideway, calibration);
}

//add 90?
//sp = screen points
void	draw_wf(t_wf wf, t_v cam_rot, t_v **screen_points, t_mlx_data mlx_data)
{
	t_v	upward;
	t_v	sideway;

	mk_isometric_matrix(w,f cam_rot, &upward, &sideway);
	apply_isometric_matrix(wf, upward, sideway, screen_points);
	draw_segments(screen_points, mlx_data);
}
