/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:30:22 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/14 17:17:44 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

t_v	div_d(t_v v, double d)
{
	v.x /= d;
	v.y /= d;
	v.z /= d;
	return (v);
}

t_v	mul_d(t_v v, double d)
{
	v.x *= d;
	v.y *= d;
	v.z *= d;
	return (v);
}

void	print_v2(t_v v)
{
	printf("(%f, %f)\n", v.x, v.y);
}

void	print_v3(t_v v)
{
	printf("(%f, %f, %f)\n", v.x, v.y, v.z);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_abs(double a)
{
	return (max(a, -a));
}

double	magnitude(t_v v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

t_v	set(t_v v)
{
	t_v new;

	new.x = v.x;
	new.y = v.y;
	new.z = v.z;
	return (new);
}

t_v	new_v(double x, double y, double z)
{
	t_v v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_v	angles_to_vector(t_v angles)
{
	t_v	horizontal;

	angles = mul_d(angles, DEG2RAD);
	horizontal = new_v(cos(angles.y), sin(angles.y), 0);
	horizontal = mul_d(horizontal, cos(angles.x));
	return (new_v(horizontal.x, sin(angles.y), horizontal.y));
}

double	dot(t_v a, t_v b)
{
	return (a.x * b.x + b.y * b.y);
}
