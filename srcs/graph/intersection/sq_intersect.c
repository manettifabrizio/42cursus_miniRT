/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:07:48 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/10 17:38:57 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

static t_shapes		*sq_to_pl(t_shapes *sh)
{
	t_plane pl;

	sh->pl.p = sh->sq.p;
	sh->pl.n = sh->sq.n;
	return (sh);
}

static void			sq_vertices(t_square *sq)
{
	t_point a;
	t_point b;

	if (fabs(sq->n.x) <= fabs(sq->n.y) && 
		(fabs(sq->n.x) <= fabs(sq->n.z)))
		a = fill_p(1, 0, (sq->n.z != 0) ? -sq->n.x / sq->n.z : 0);
	else if (fabs(sq->n.z) <= fabs(sq->n.y) &&
		(fabs(sq->n.z) <= fabs(sq->n.x)))
		a = fill_p((sq->n.x != 0) ? -sq->n.z / sq->n.x : 0, 0, 1);
	else if (fabs(sq->n.y) <= fabs(sq->n.x) &&
		(fabs(sq->n.x) <= fabs(sq->n.z)))
		a = fill_p(0, 1, (sq->n.z != 0) ? -sq->n.y / sq->n.z : 0);
	a = normalize(a);
	b = normalize(cross_2(sq->n, a));
	sq->v0 = sum(sq->p, mul(sum(a, b), sq->h / 2));
	sq->v1 = sum(sq->p, mul(sub(a, b), sq->h / 2));
	sq->v2 = sum(sq->p, mul(sum(a, b), -(sq->h / 2)));
	sq->v3 = sum(sq->p, mul(sub(b, a), sq->h / 2));
}

int					sq_intersect(const t_ray ray, t_shapes *sh, double *t)
{
	if (pl_intersect(ray, sq_to_pl(sh), t))
	{
		sq_vertices(&(sh->sq));
		sh->tr.v0 = sh->sq.v0;
		sh->tr.v1 = sh->sq.v1;
		sh->tr.v2 = sh->sq.v2;
		if (tr_intersect(ray, sh, t))
		{
			sh->objclr = sh->sq.clr;
			return (1);
		}
		sh->tr.v1 = sh->sq.v3;
		if (tr_intersect(ray, sh, t))
		{
			sh->objclr = sh->sq.clr;
			return (1);
		}
	}
	return (0);
}