/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:23:09 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 20:03:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

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

double		point_dist(t_point p1, t_point p2)
{
	return (sqrt(pow((p2.x - p1.x), 2) + \
			pow((p2.y - p1.y), 2) + \
			pow((p2.z - p1.z), 2)));
}
