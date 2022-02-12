/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:30:22 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/12 22:07:49 by maabidal         ###   ########.fr       */
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

t_v	new_v()
{
	t_v v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	return (v);
}

t_v	set(t_v v)
{
	t_v new;

	new.x = v.x;
	new.y = v.y;
	new.z = v.z;
	return (new);
}
