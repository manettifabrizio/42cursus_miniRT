/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 10:48:01 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/08 12:21:03 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

// t_point	positive(t_point p)
// {
// 	p.x = (p.x > 0) ? p.x * -1 : p.x;
// 	p.y = (p.y > 0) ? p.y * -1 : p.y;
// 	p.z = (p.z > 0) ? p.z * -1 : p.z;
// 	return (p);
// }

int		pl_intersect(const t_ray ray, t_plane pl, float *t, \
	t_color *objcolor)
{ //da ricontrollare quando faccio la luce
	float	denom;

	// pl.v = positive(pl.v);
	pl.v = normalize(pl.v);
	// printf("pl.p.x = %f\npl.p.y = %f\npl.p.z = %f\n", pl.p.x, pl.p.y, pl.p.z);
	// printf("pl.v.x = %f\npl.v.y = %f\npl.v.z = %f\n", pl.v.x, pl.v.y, pl.v.z);
	denom = dot_product_2(pl.v, ray.dir);
	// printf("denom = %f\n", denom);
	// if (denom > 1e-6 || denom < -1e-6) 
	// {
							//con la sottrazione li allinei indipendentemente
		*t = dot_product_2(vector_sub(pl.p, ray.orig), pl.v) / denom;
		// printf ("*t = %f\n", *t);
		if (*t >= 0)
		{
			// printf("hit.r = %u, hit.g = %u, hit.b = %u\n", pl.clr.r, pl.clr.g, pl.clr.b);
			*objcolor = pl.clr;
			return (1);
		}
	// }
	return (0);
}