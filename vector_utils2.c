/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:30:22 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/17 22:53:25 by maabidal         ###   ########.fr       */
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

double	magnitude(t_v v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_v	new_v(double x, double y, double z)
{
	t_v	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double	dot(t_v a, t_v b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
