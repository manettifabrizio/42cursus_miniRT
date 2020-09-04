/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:07:48 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/02 16:38:34 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

t_shapes		*sq_to_pl(t_shapes *sh)
{
	t_plane pl;

	sh->pl.p = sh->sq.p;
	sh->pl.n = sh->sq.n;
	return (sh);
}

int			sq_intersect(const t_ray ray, t_shapes *sh, double *t)
{
	t_point phit;
	double	halfh;

	if (pl_intersect(ray, sq_to_pl(sh), t))
	{
		halfh = sh->sq.h / 2;
		phit = vec_sum(ray.orig, point_mul(ray.dir, *t));
		if (phit.x > (sh->sq.p.x - halfh) && phit.x < (sh->sq.p.x + halfh) &&
			phit.y > (sh->sq.p.y - halfh) && phit.y < (sh->sq.p.y + halfh) &&
			phit.z > (sh->sq.p.z - halfh) && phit.z < (sh->sq.p.z + halfh))
		{
			sh->nhit = sh->sq.n;
			sh->objclr = sh->sq.clr;
			return (1);
		}
	}
	return (0);
}