/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:33:10 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/14 23:33:40 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include<stdio.h>

#include<stdlib.h>
# include "mlx.h"
# include <fcntl.h>
# include "libft.h"
# include <math.h>
# ifndef CREAT_F
#  define CRAET_F O_WRONLY | O_CREAT | O_TRUNC
# endif
# ifndef X
#  define X 0
# endif
# ifndef Y
#  define Y 1
# endif
# ifndef Z
#  define Z 2
# endif

//vector
typedef struct s_v
{
	double	x;
	double	y;
	double	z;
}	t_v;

t_v	sum(t_v a, t_v b);
t_v	dif(t_v a, t_v b);
t_v	mul(t_v a, t_v b);
t_v	di(t_v num, t_v denum);
t_v	normalized(t_v v);
t_v	div_d(t_v v, double d);
t_v	mul_d(t_v v, double d);
double	max(double a, double b);
double	ft_abs(double a);
double	magnitude(t_v v);
t_v	new_v();
t_v	set(t_v v);
void	print_v2(t_v v);
void	print_v3(t_v v);
t_v	angles_to_vector(t_v angles);
double	dot(t_v a, t_v b);

//wireframe
typedef struct s_wf
{
	double	**heights;
	int	width;
	int	length;
	double	max_height;
}	t_wf;
t_wf	parse_file(char *pathname);

//mlx
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

void	draw_line(t_v point, t_v end, t_mlx_data mlx_data);
t_mlx_data	init_mlx();
//display
# ifndef PIX_PER_SIDE
#  define PIX_PER_SIDE 1200
# endif
# ifndef FRACTION_OF_SCREEN
#  define FRACTION_OF_SCREEN 0.75
# endif
# ifndef COLOR
#  define COLOR 244 << 8
# endif
# ifndef DEG2RAD
#  define DEG2RAD 0.0174533
# endif
# ifndef STARTING_ROTX
#  define STARTING_ROTX -45.0
# endif
# ifndef STARTING_ROTY
#  define STARTING_ROTY 80.0
# endif
#endif
//sp = screen_points
typedef struct s_display_data
{
	t_v	cam_rot;
	t_v	**sp;
}	t_display_data;
void	draw_wf(t_wf wf, t_v cam_rot, t_v **screen_points, t_mlx_data mlx_data);

