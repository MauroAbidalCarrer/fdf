/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:04:12 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/12 23:44:08 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_v	set_v_from_av(char **av)
{
	t_v	v;

	v.x = atof(av[0]);
	v.y = atof(av[1]);
	return (v);
}

void	put_pixel(t_v v, int win_width, int win_height, void *win, void *mlx)
{
	int	x;
	int	y;

	v.x = floor(v.x);
	v.y = floor(v.y);
	x = win_width / 2 + (int)v.x;
	y = win_height / 2 - (int)v.y;
	mlx_pixel_put(mlx, win, x, y, COLOR);
}


void	draw_line(t_v point, t_v end, int win_width, int win_height, void *win, void *mlx)
{
	t_v dir;

	dir = normalized(dif(end, point));
	put_pixel(point, win_width, win_height, win, mlx);
	while ((int)point.x != (int)end.x || (int)point.y != (int)end.y)
	{
		point = sum(point, dir);
		put_pixel(point, win_width, win_height, win, mlx);
	}
}

int	main(int ac, char **av)
{
	t_v	start;
	t_v	end;
	void	*mlx_ptr;
	void	*win_ptr;


	start = set_v_from_av(av + 1);
	end = set_v_from_av(av + 3);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "oui");

	draw_line(start, end, 1000, 1000, win_ptr, mlx_ptr);

	mlx_loop(mlx_ptr);
}
