/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_transformation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:53:03 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/15 15:48:25 by maabidal         ###   ########.fr       */
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
			point = new_v((double)(x - wf.width / 2), wf.heights[x][y], (double)(y - wf.length / 2));
			sp[x][y].x = dot(sideway, point);
			sp[x][y].y = dot(upward, point);
//printf("point = (%f, %f, %f), upward = (%f, %f, %f), dot(upward, point) = %f\n", point.x, point.y, point.z, upward.x, upward.y, upward.z, dot(upward, point));
		}
	}
}

void	mk_isometric_matrix(t_wf wf, t_v cam_rot, t_v *upward, t_v *sideway)
{
	t_v	max_point;
	double	calibration;

//create to_screen matrix
t_v angles_upward;
angles_upward.x = 90.0 + cam_rot.x;
angles_upward.y = cam_rot.y;
angles_upward.z = 0;
	*upward = angles_to_vector(angles_upward /*sum(cam_rot, new_v(90, 0, 0))*/);

t_v angles_sideway;
angles_sideway.x = 0.0;
angles_sideway.y = cam_rot.y - 90;
angles_sideway.z = 0;
	*sideway = angles_to_vector(angles_sideway);

//calibrate
	calibration = (double)PIX_PER_SIDE / 2.0;
	max_point = new_v((double)wf.width, wf.max_height, (double)wf.length);
	calibration /= magnitude(max_point);
//printf("magnitude(max_point) = %f\n", magnitude(max_point));
	//calibration *= FRACTION_OF_SCREEN;
	*upward = mul_d(*upward, calibration);
	*sideway = mul_d(*sideway, calibration);
}

//add 90?
//sp = screen points
void	draw_wf(t_all_data *data)
{
	t_v	upward;
	t_v	sideway;

	mk_isometric_matrix(*data->wf, data->display->cam_rot, &upward, &sideway);
	apply_isometric_matrix(*data->wf, upward, sideway, data->display->sp);
	draw_segments(data->display->sp,  *data->wf, *data->mlx);
}
