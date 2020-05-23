/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:29:54 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/23 10:00:22 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int		intersect(const t_ray ray, const t_sphere sp, float *t)
{
	t_point	l;
	float	a;
	float 	b;
	float	c;
	float	dist;
	float t0 = 0.0, t1 = 0.0;

	dist = point_dist(ray.orig, sp.ctr); //questo è un porcaio
	l.x = dist; l.y = dist; l.z = dist;
	a = dot_product(ray.dir); //dovrebbe essere sempre 1
	b = 2 * dot_product(l); //teroricamente dovrebbe essere 2 * ray.dir * l;
	c = dot_product(l) - (sp.diam * 0.5); // dovrebbe essere l^2 - r 
	if (!(quad_solver(a, b, c, t0, t1)))
		return (0);
	if (t0 > t1)
		ft_swap_f(&t0, &t1);
	if (t1 < 0)
	{
		t1 = t0;
		if (t0 < 0)
			return (0);
	}
	*t = t0;
	return (1);
}