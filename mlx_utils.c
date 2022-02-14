/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:38:56 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/14 16:38:58 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

