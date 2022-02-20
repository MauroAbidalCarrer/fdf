/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:33:10 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/20 23:18:08 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include <fcntl.h>
# include "libft.h"
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

t_v		sum(t_v a, t_v b);
t_v		dif(t_v a, t_v b);
t_v		mul(t_v a, t_v b);
t_v		di(t_v num, t_v denum);
t_v		normalized(t_v v);
t_v		div_d(t_v v, double d);
t_v		mul_d(t_v v, double d);
double	max(double a, double b);
double	ft_abs(double a);
double	magnitude(t_v v);
t_v		new_v(double x, double y, double z);
t_v		set(t_v v);
void	print_v2(t_v v);
void	print_v3(t_v v);
t_v		angles_to_vector(t_v angles);
double	dot(t_v a, t_v b);
t_v		lerp_v(t_v a, t_v b, double t);
//wireframe
typedef struct s_wf
{
	t_v		**vertices;
	int		sizes[2];
	double	max_iso_magnitude;
	double	max_per_magnitude;
	double	max_height;
	double	min_height;
}	t_wf;
t_wf	parse_file(char *pathname);

//mlx
typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
}	t_mlx_data;
typedef struct s_point_n_col
{
	t_v	point;
	t_v	col;
}	t_point_n_col;
//display
# ifndef PIX_PER_SIDE
#  define PIX_PER_SIDE 1200
# endif
# ifndef HALF_PIX_PIX_PER_SIDE
#  define HALF_PIX_PIX_PER_SIDE 600.0
# endif
# ifndef FRACTION_OF_SCREEN
#  define FRACTION_OF_SCREEN 0.75
# endif
# ifndef COLOR
#  define COLOR 0x00ff0000
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
# ifndef ISO_MODE
#  define ISO_MODE 0
# endif
# ifndef PER_MODE
#  define PER_MODE 1
# endif
# ifndef NEAR_PER_PLANE
#  define NEAR_PER_PLANE 0.1
# endif
# ifndef NEAR_PLANE
#  define NEAR_PLANE 1
# endif
# ifndef LOW_COLOR
#  define LOW_COLOR 0x0000ff00
# endif
# ifndef HIGH_COLOR
#  define HIGH_COLOR 0x000000ff
# endif
//sp = screen_points
typedef struct s_display_data
{
	t_v		cam_rot;
	t_v		**sp;
	double	zoom;
	char	display_mode;
	double	distance;
	t_v		low_col;
	t_v		high_col;
}	t_display_data;

typedef struct s_matrix
{
	t_v	i;
	t_v	j;
	t_v	k;
}	t_matrix;
void	apply_isometric_matrix(t_wf wf, t_matrix matrix, t_v **sp);
void	mk_isometric_matrix(t_wf wf, t_display_data display, t_matrix *matrix);
void	mk_perspective_matrix(t_display_data display, t_matrix *matrix);
void	draw_line(t_point_n_col point, t_point_n_col end, t_mlx_data mlx_data);
//all
typedef struct s_all_data
{
	t_display_data	*display;
	t_mlx_data		*mlx;
	t_wf			*wf;
}	t_all_data;

void	draw_wf(t_all_data *data);
int		on_keyboard_pressed(int keycode, t_all_data *data);
int		on_mouse_move(int x, int y, t_all_data *data);
int		on_keyboard_press(int keycode, t_all_data *data);
#endif
