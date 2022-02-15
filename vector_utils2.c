/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:30:22 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/15 21:13:13 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

/*
void	print_v2(t_v v)
{
	printf("(%f, %f)\n", v.x, v.y);
}

void	print_v3(t_v v)
{
	printf("(%f, %f, %f)\n", v.x, v.y, v.z);
}
*/

double	magnitude(t_v v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

t_v	new_v(double x, double y, double z)
{
	t_v v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double	dot(t_v a, t_v b)
{
//printf("dot((%f, %f, %f), (%f, %f, %f)) = %f\n", a.x, a.y, a.z, b.x, b.y, b.z, (a.x * b.x + a.y * b.y));
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
