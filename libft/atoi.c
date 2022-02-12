/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:24:58 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/12 23:59:42 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include"libft.h"

static int	inrange(char c, char a, char b)
{
	return (c >= a && c <= b);
}

static int	iswhite(char c)
{
	return (c == ' ' || inrange(c, 9, 13));
}

int	ft_atoi(const char *nptr)
{
	long	sign;
	long	nb;

	while (iswhite(*nptr))
		nptr++;
	sign = 1 - 2 * (*nptr == '-');
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	nb = 0;
	while (inrange(*nptr, '0', '9'))
		nb = nb * 10 + *nptr++ - '0';
	return ((int)(nb * sign));
}
