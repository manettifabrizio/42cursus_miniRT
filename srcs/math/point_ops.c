/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:48:28 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/16 15:38:54 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_point		sum(t_point p1, t_point p2)
{
	t_point p3;

	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	p3.z = p1.z + p2.z;

	//x norma sqrt(pow(p3.x, 2) + pow(p3.y, 2) + pow(p3.z, 2))
	return (p3);
}

t_point		sub(t_point p1, t_point p2)
{
	t_point p3;

	p3.x = p1.x - p2.x;
	p3.y = p1.y - p2.y;
	p3.z = p1.z - p2.z;

	//x norma sqrt(pow(p3.x, 2) + pow(p3.y, 2) + pow(p3.z, 2))
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

double		dot_2(t_point p1, t_point p2) //scalare
{
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}

t_point		cross_2(t_point p1, t_point p2)
{
	t_point	p3;

	p3.x = p1.y * p2.z - p1.z * p2.y;
	p3.y = p1.z * p2.x - p1.x * p2.z;
	p3.z = p1.x * p2.y - p1.y * p2.x;
	return (p3);
}

t_color		clr_sum(t_color clr0, t_color clr1)
{
	t_color clr;

	clr.r = clr0.r + clr1.r;
	clr.g = clr0.g + clr1.g;
	clr.b = clr0.b + clr1.b;
	return (clr);
}

t_color 	clr_mul(t_color clr0, t_color clr1)
{
	t_color clr;

	clr.r = clr0.r * clr1.r;
	clr.g = clr0.g * clr1.g;
	clr.b = clr0.b * clr1.b;
	return (clr);
}

t_color		clr_d_mul(t_color clr, double x)
{
	t_color clr1;

	clr1.r = clr.r * x;
	clr1.g = clr.g * x;
	clr1.b = clr.b * x;
	return (clr1);
}

t_color		mix_clr(t_color light, t_color shape, double ratio)
{
	t_color clr;

	clr.r = ratio * light.r / 255 * shape.r;
	clr.g = ratio * light.g / 255 * shape.g;
	clr.b = ratio * light.b / 255 * shape.b;
	return (clr);
}

t_color		max_clr(t_color clr, t_color objclr)
{
	if (clr.r > objclr.r)
		clr.r = objclr.r;
	if (clr.g > objclr.g)
		clr.g = objclr.g;
	if (clr.b > objclr.b)
		clr.b = objclr.b;
	return (clr);
}