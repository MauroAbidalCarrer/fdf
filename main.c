/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:16:38 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/15 21:34:08 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_all(t_all_data *data)
{
	free_tab((void **)data->wf->heights, data->wf->width);
	free_tab((void **)data->display->sp, data->wf->width);
	free(data->mlx->mlx);
}

int	on_keyboard_pressed(int keycode, t_all_data *data)
{
		t_v	rot_offset;

		if (keycode == KEY_ESC_M)
		{
			mlx_destroy_window(data->mlx->mlx, data->mlx->win);
			free_all(data);
			exit(0);
		}
		rot_offset.x += (double)(keycode == KEY_UP_M);
		rot_offset.x -= (double)(keycode == KEY_DOWN_M);
		rot_offset.y += (double)(keycode == KEY_LEFT_M);
		rot_offset.y -= (double)(keycode == KEY_RIGHT_M);
		if (rot_offset.x || rot_offset.y)
		{
			rot_offset = mul_d(rot_offset, 4);
			data->display->cam_rot = sum(data->display->cam_rot, rot_offset);
			draw_wf(data);
		}
		return (0);
}

int	on_mouse_move(int x, int y, t_all_data *data)
{
	t_v	rot_offset;
	static int	last_x;
	static int	last_y;
	int			first_call;

	rot_offset.y = -(double)(last_x - x) / 10.0;
	rot_offset.x = -(double)(last_y - y) / 7.0;
	first_call = (last_x == 0 && last_y == 0);
	last_x = x;
	last_y = y;
	rot_offset.z = 0;
	//rot_offset = div_d(rot_offset, 10);
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

//TAKE CARE OF FLOATING POINTS IN FILE!!!!!!!!!!!!!!!!!!!!!!!!!!------------------------------------------------
//sp = screen points
int	main(int ac, char **av)
{
	t_wf			wf;
	t_mlx_data		mlx;
	t_display_data	display;
	t_all_data		data;

	if (ac != 2)
		return (1);
	wf = parse_file(av[1]);
	mlx = init_mlx();
	display.sp = (t_v **)alloc_tab(sizeof(t_v), wf.width, wf.length);
	if (display.sp == NULL)
	{
		free_tab((void **)wf.heights, wf.width - 1);
		//mlx close?
		return (1);
	}
//	display.cam_rot;// = new_v(STARTING_ROTX,  STARTING_ROTY + 90.0, 0);
	display.cam_rot.x = 50.0;
	display.cam_rot.y = 45.0;
	display.cam_rot.z = 0;
	display.zoom = 1;
	display.is_processing = 0;
	display.display_mode = ISO_MODE;
/*
printf("cam_rot = ");print_v3(cam_rot);
printf("\nforward = ");print_v3(angles_to_vector(cam_rot));
printf("\n");
*/

	data.wf = &wf;
	data.mlx = &mlx;
	data.display = &display;

	draw_wf(&data);
mlx_key_hook(mlx.win, &on_keyboard_pressed, &data);//escape
mlx_hook(mlx.win, 6, 1L<<6, &on_mouse_move, &data);//mouse
mlx_hook(mlx.win, 2, 1L<<0, &on_keyboard_press, &data);//zoom
//mlx_mouse_hook(mlx.win, &on_mouse_button, &data);
	mlx_loop(mlx.mlx);
}
