/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 10:48:01 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/02 15:23:40 by fmanetti         ###   ########.fr       */
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

int		pl_intersect(const t_ray ray, t_shapes *sh, double *t)
{
	// printf("pl.p.x = %f\npl.p.y = %f\npl.p.z = %f\n", pl.p.x, pl.p.y, pl.p.z);
	// printf("pl.n.x = %f\npl.n.y = %f\npl.n.z = %f\n", pl.n.x, pl.n.y, pl.n.z);
						//con la sottrazione li allinei indipendentemente
	*t = dot_2(vec_sub(sh->pl.p, ray.orig), sh->pl.n) /
		dot_2(sh->pl.n, ray.dir);
	if (*t > 0)
	{
		sh->objclr = sh->pl.clr;
		return (1);
	}
	return (0);
}