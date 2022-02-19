/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:16:38 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/19 22:18:07 by maabidal         ###   ########.fr       */
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

t_mlx_data	init_mlx(void)
{
	t_mlx_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, PIX_PER_SIDE, PIX_PER_SIDE, "fdf");
	return (data);
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

int	main(int ac, char **av)
{
	t_wf			wf;
	t_mlx_data		mlx;
	t_display_data	display;
	t_all_data		data;

	if (ac != 2)
		return (1);
	wf = parse_file(av[1]);
	display.sp = (t_v **)alloc_tab(sizeof(t_v), wf.sizes[0], wf.sizes[1]);
	if (display.sp == NULL)
		return (free_tab((void **)wf.vertices, wf.sizes[0] - 1), 1);
	mlx = init_mlx();
	display = init_display(display);
	data.wf = &wf;
	data.mlx = &mlx;
	data.display = &display;
	draw_wf(&data);
	mlx_key_hook(mlx.win, &on_keyboard_pressed, &data);
	if (BONUS)
	{
		mlx_hook(mlx.win, 6, 1 << 6, &on_mouse_move, &data);
		mlx_hook(mlx.win, 2, 1, &on_keyboard_press, &data);
	}
	mlx_loop(mlx.mlx);
}
