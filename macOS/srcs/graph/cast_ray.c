/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:19:02 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/02 20:42:06 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			get_surface_data(t_ray ray, double t, t_shapes *hitobj)
{
	double m;

	hitobj->phit = sum(ray.orig, mul(ray.dir, t));
	if (hitobj->type == 0)
		hitobj->nhit = normalize(sub(hitobj->phit, hitobj->sp.c));
	else if (hitobj->type == 1)
		hitobj->nhit = hitobj->pl.n;
	else if (hitobj->type == 2)
		hitobj->nhit = hitobj->sq.n;
	else if (hitobj->type == 3)
	{
		m = dot_2(ray.dir, hitobj->cy.n) * t + dot_2(sub(ray.orig,
								hitobj->cy.p), hitobj->cy.n);
		hitobj->nhit = normalize(sub(sub(hitobj->phit, hitobj->cy.p),
											mul(hitobj->cy.n, m)));
	}
	else if (hitobj->type == 4)
		hitobj->nhit = hitobj->tr.n;
}

static void			get_light_data(t_light *l, t_shapes hitobj)
{
	l->dir = sub(hitobj.phit, l->p);
	l->intensity = clr_d_mul(l->clr, l->rat);
	l->dir = normalize(l->dir);
	l->shray.orig = sum(hitobj.phit, mul(l->dir, -BIAS));
	l->shray.dir = normalize(mul(l->dir, -1));
}

static void			shadow_and_fratio(t_ray ray, double *fratio, t_uint *shadow,
										t_objects obj)
{
	double t;

	t = 0;
	(*shadow) = trace(obj.ltmp->shray, &obj, &t, &(obj.hitobj2)) ? 0 : 1;
	if ((t > point_dist(obj.hitobj.phit, obj.ltmp->p)) ||
		(point_dist(obj.hitobj.phit, obj.ltmp->p) - t < 1e-03))
		(*shadow) = 1;
	if (dot_2(ray.dir, obj.hitobj.nhit) > 1e-08)
		(*shadow) = 0;
	(*fratio) = dot_2(obj.hitobj.nhit, obj.ltmp->shray.dir);
	if ((*fratio) < 0)
		(*fratio) = 0;
}

static t_color		compute_clr(t_shapes o, t_light l, double fratio,
												double shad)
{
	t_color clr;

	clr = mix_clr(l.clr, o.objclr, l.rat * fratio * shad);
	return (clr);
}

t_color				cast_ray(t_ray ray, t_setting set, t_objects obj)
{
	double		t;
	t_color		ambcolor;
	t_color		hitcolor;
	double		fratio;
	t_uint		shadow;

	obj.ltmp = obj.lhead;
	hitcolor = fill_clr_3(0, 0, 0);
	if (trace(ray, &obj, &t, &(obj.hitobj)))
	{
		ambcolor = mix_clr(set.amblclr, obj.hitobj.objclr, 1);
		get_surface_data(ray, t, &(obj.hitobj));
		while (obj.ltmp)
		{
			get_light_data(obj.ltmp, obj.hitobj);
			shadow_and_fratio(ray, &fratio, &shadow, obj);
			hitcolor = clr_sum(hitcolor, compute_clr(obj.hitobj, *obj.ltmp,
				fratio, shadow));
			obj.ltmp = obj.ltmp->next;
		}
		hitcolor = max_clr(clr_sum(ambcolor, hitcolor), obj.hitobj.objclr);
	}
	return (hitcolor);
}