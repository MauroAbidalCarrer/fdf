/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:16:38 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/14 23:35:37 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//sp = screen points
int	main(int ac, char **av)
{
	t_wf wf;
	t_mlx_data	data;
	t_v	**sp;

	if (ac != 2)
		return (1);
	wf = parse_file(av[1]);
	data = init_mlx();
	sp = (t_v **)alloc_tab(sizeof(t_v), wf.width, wf.length);
	if (sp == NULL)
	{
		free_tab((void **)wf.heights, wf.width - 1);
		//mlx close?
		return (1);
	}
	t_v cam_rot;// = new_v(STARTING_ROTX,  STARTING_ROTY + 90.0, 0);
	cam_rot.x = 50.0;
	cam_rot.y = 45.0;
	cam_rot.z = 0;
/*
printf("cam_rot = ");print_v3(cam_rot);
printf("\nforward = ");print_v3(angles_to_vector(cam_rot));
printf("\n");
*/

	draw_wf(wf, cam_rot, sp, data);
	mlx_loop(data.mlx_ptr);
}
