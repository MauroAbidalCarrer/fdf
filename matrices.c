/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:02:04 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/17 17:25:09 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_v	angles_to_vector(t_v angles)
{
	t_v	horizontal;

	angles =  mul_d(angles, DEG2RAD);
	horizontal = new_v(cos(angles.y), sin(angles.y), 0);
	horizontal = mul_d(horizontal, cos(angles.x));
	return (new_v(horizontal.x, sin(angles.x), horizontal.y));
}

t_matrix	mk_rotation_matrix(t_v angles)
{
	t_v	cam_rot;
	t_matrix matrix;
	t_v	angles_upward;
	t_v	angles_sideway;

	angles_upward.x = 90.0 + angles.x;
	angles_upward.y = angles.y;
	angles_upward.z = 0;
	matrix.j = angles_to_vector(angles_upward);
	angles_sideway.x = 0.0;
	angles_sideway.y = angles.y + 90;
	angles_sideway.z = 0;
	matrix.i = angles_to_vector(angles_sideway);
	matrix.k = angles_to_vector(angles);
	return (matrix);
}

void	mk_isometric_matrix(t_wf wf, t_display_data display, t_matrix *matrix)
{
	double	calibration;

	*matrix = mk_rotation_matrix(display.cam_rot);
	calibration = HALF_PIX_PIX_PER_SIDE;
	calibration /= wf.max_iso_magnitude;
	calibration *= display.zoom;
	matrix->j = mul_d(matrix->j, calibration);
	matrix->i = mul_d(matrix->i, calibration);
}

void	mk_perspective_matrix(t_display_data display, t_matrix *matrix)
{
	display.cam_rot = mul_d(display.cam_rot, -1);
	*matrix = mk_rotation_matrix(display.cam_rot);
}
