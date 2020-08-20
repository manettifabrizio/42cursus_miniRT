/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:48:28 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/14 12:44:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_point		vec_sum(t_point p1, t_point p2)
{
	t_point p3;

	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	p3.z = p1.z + p2.z;

	//x norma sqrt(pow(p3.x, 2) + pow(p3.y, 2) + pow(p3.z, 2))
	return (p3);
}

t_point		vec_sub(t_point p1, t_point p2)
{
	t_point p3;

	p3.x = p1.x - p2.x;
	p3.y = p1.y - p2.y;
	p3.z = p1.z - p2.z;

	//x norma sqrt(pow(p3.x, 2) + pow(p3.y, 2) + pow(p3.z, 2))
	return (p3);
}

float		dot_1(t_point p)
{
	return (p.x * p.x + p.y * p.y + p.z * p.z);
}

float		dot_2(t_point p1, t_point p2) //scalare
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

t_point		point_mul(t_point p1, t_point p2)
{
	t_point p3;

	p3.x = p1.x * p2.x;
	p3.y = p1.y * p2.y;
	p3.z = p1.z * p2.z;
	return (p3); 
}