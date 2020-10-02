/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:27:16 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/02 17:54:14 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		tr_intersect(const t_ray ray, t_shapes *sh, double *t)
{
	double		det;
	t_cobar		c;

	c.pvec = cross_2(ray.dir, sub(sh->tr.v2, sh->tr.v0));
	det = dot_2(sub(sh->tr.v1, sh->tr.v0), c.pvec);
	if (fabs(det) < 1e-08)
		return (0);
	c.tvec = sub(ray.orig, sh->tr.v0);
	c.u = dot_2(c.tvec, c.pvec) * (1 / det);
	if (c.u < 0 || c.u > 1)
		return (0);
	c.qvec = cross_2(c.tvec, sub(sh->tr.v1, sh->tr.v0));
	c.v = dot_2(ray.dir, c.qvec) * (1 / det);
	if (c.v < 0 || c.u + c.v > 1)
		return (0);
	*t = dot_2(sub(sh->tr.v2, sh->tr.v0), c.qvec) * (1 / det);
	if (*t < 0)
		return (0);
	sh->objclr = sh->tr.clr;
	return (1);
}
