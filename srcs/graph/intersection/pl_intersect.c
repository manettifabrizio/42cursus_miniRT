/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 10:48:01 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/01 18:26:43 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

int		pl_intersect(const t_ray ray, const t_plane pl, float *t, \
	t_color *hitcolor)
{
	float	denom;

	// tutto deve arrivare normalizzato controllares
	printf("pl.p.x = %f\npl.p.y = %f\npl.p.z = %f\n", pl.p.x, pl.p.y, pl.p.z);
	printf("pl.v.x = %f\npl.v.y = %f\npl.v.z = %f\n", pl.v.x, pl.v.y, pl.v.z);
	denom = dot_product_2(pl.v, ray.dir);
	if (denom > 1e-6) 
	{
		// *t = (dot_product_2(vector_sub(pointplane_dist(ray, pl), ray.orig), \
		// 	pl.v)) / denom;
		t_point c = vector_sub(pl.p, ray.orig);
		*t = dot_product_2(c, pl.v) / denom;
		if (*t >= 0)
		{
			printf("hit.r = %u, hit.g = %u, hit.b = %u\n", pl.clr.r, pl.clr.g, pl.clr.b);
			*hitcolor = fill_clr_3(pl.clr.r, pl.clr.g, pl.clr.b);
			return (1);
		}
	}
	return (0);
}