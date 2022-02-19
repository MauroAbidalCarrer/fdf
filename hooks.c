/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:01:52 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/17 23:08:19 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	on_keyboard_pressed(int keycode, t_all_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		free_tab((void **)data->wf->vertices, data->wf->sizes[0] - 1);
		free_tab((void **)data->display->sp, data->wf->sizes[0] - 1);
		free(data->mlx->mlx);
		exit(0);
	}
	if (keycode == 35)
	{
		data->display->display_mode = !data->display->display_mode;
		draw_wf(data);
	}
	return (0);
}

int	on_mouse_move(int x, int y, t_all_data *data)
{
	t_v			rot_offset;
	static int	last_x;
	static int	last_y;
	int			first_call;

	rot_offset.y = -(double)(last_x - x) / 10.0;
	rot_offset.x = -(double)(last_y - y) / 7.0;
	first_call = (last_x == 0 && last_y == 0);
	last_x = x;
	last_y = y;
	rot_offset.z = 0;
	if (!first_call)
	{
		data->display->cam_rot = sum(data->display->cam_rot, rot_offset);
		draw_wf(data);
	}
	return (0);
}

int	on_keyboard_press(int keycode, t_all_data *data)
{
	if (keycode == 13)
		data->display->zoom *= 1.3;
	else if (keycode == 1)
		data->display->zoom /= 1.3;
	draw_wf(data);
	return (0);
}
