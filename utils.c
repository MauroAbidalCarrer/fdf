/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:02:25 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/17 22:52:58 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_v	conv_int_col(int color)
{
	t_v	col;

	col.x = (double)((color >> 8) & 255);
	col.y = (double)((color >> 4) & 255);
	col.z = (double)(color & 255);
	return (col);
}

t_display_data	init_display(t_display_data display)
{
	display.cam_rot.x = 50.0;
	display.cam_rot.y = 45.0;
	display.cam_rot.z = 0;
	display.zoom = 1;
	display.display_mode = ISO_MODE;
	display.low_col = conv_int_col(LOW_COLOR);
	display.high_col = conv_int_col(HIGH_COLOR);
	return (display);
}
