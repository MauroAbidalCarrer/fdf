/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:59:39 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/14 19:48:54 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_v	sum(t_v a, t_v b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_v	dif(t_v a, t_v b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_v	mul(t_v a, t_v b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

t_v	di(t_v num, t_v denum)
{
	num.x /= denum.x;
	num.y /= denum.y;
	if (denum.z != 0)
		num.z /= denum.z;
	return (num);
}

t_v	normalized(t_v v)
{
	double	mag;

	mag = magnitude(v);
	v.x /= mag;
	v.y /= mag;
	return (v);
}
