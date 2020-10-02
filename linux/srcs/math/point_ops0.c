/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_ops0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:48:28 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/02 21:27:46 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point		sum(t_point p1, t_point p2)
{
	t_point p3;

	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	p3.z = p1.z + p2.z;
	return (p3);
}

t_point		sub(t_point p1, t_point p2)
{
	t_point p3;

	p3.x = p1.x - p2.x;
	p3.y = p1.y - p2.y;
	p3.z = p1.z - p2.z;
	return (p3);
}

t_point		mul(t_point p1, double x)
{
	t_point p3;

	p3.x = p1.x * x;
	p3.y = p1.y * x;
	p3.z = p1.z * x;
	return (p3);
}

double		dot_1(t_point p)
{
	return (p.x * p.x + p.y * p.y + p.z * p.z);
}

double		dot_2(t_point p1, t_point p2)
{
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}
