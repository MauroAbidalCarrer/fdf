/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:33:10 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/13 18:29:37 by maabidal         ###   ########.fr       */
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
# ifndef COLOR
#  define COLOR 244 << 8
# endif
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

typedef struct s_v
{
	double	x;
	double	y;
	double	z;
}	t_v;

//wf = wireframe
//width = X, length = Y, height = Z
typedef struct s_wf
{
	double **heights;
	int	width;
	int	length;
	double	max_height;
}	t_wf;

//vector utils
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
#endif
