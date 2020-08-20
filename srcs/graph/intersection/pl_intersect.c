/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 10:48:01 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/14 14:31:32 by fmanetti         ###   ########.fr       */
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

int		pl_intersect(const t_ray ray, const t_plane pl, float *t, \
			t_color *objcolor)
{
	// printf("pl.p.x = %f\npl.p.y = %f\npl.p.z = %f\n", pl.p.x, pl.p.y, pl.p.z);
	// printf("pl.n.x = %f\npl.n.y = %f\npl.n.z = %f\n", pl.n.x, pl.n.y, pl.n.z);
						//con la sottrazione li allinei indipendentemente
	*t = dot_2(vec_sub(pl.p, ray.orig), pl.n) / \
		dot_2(pl.n, ray.dir);
	// printf ("*t = %f\n", *t);
	if (*t >= 0)
	{
		// printf("hit.r = %u, hit.g = %u, hit.b = %u\n", pl.clr.r, pl.clr.g, pl.clr.b);
		*objcolor = pl.clr;
		return (1);
	}
	return (0);
}