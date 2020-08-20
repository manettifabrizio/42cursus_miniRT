/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:07:48 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/14 14:30:05 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

t_plane		sq_to_pl(const t_square sq)
{
	t_plane pl;

	pl.p = sq.p;
	pl.n = sq.n;
	return (pl);
}

int			sq_intersect(const t_ray ray, const t_square sq, float *t, \
				t_color *objcolor)
{
	t_point hitp;
	float	halfh;

	if (pl_intersect(ray, sq_to_pl(sq), t, objcolor))
	{
		halfh = sq.h / 2;
		hitp = vec_sum(ray.orig, point_mul(ray.dir, fill_point_1(*t)));
		if (hitp.x > (sq.p.x - halfh) && hitp.x < (sq.p.x + halfh) && \
			hitp.y > (sq.p.y - halfh) && hitp.y < (sq.p.y + halfh) && \
			hitp.z > (sq.p.z - halfh) && hitp.z < (sq.p.z + halfh))
		{
			*objcolor = sq.clr;
			return (1);
		}
	}
	return (0);
}