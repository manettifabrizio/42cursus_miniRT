/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:19:02 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 00:45:55 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static void		get_surface_data(t_ray ray, double t, t_shapes *hitobj)
{
	double m;

	hitobj->phit = sum(ray.orig, mul(ray.dir, t));
	// print_point(hitobj->phit, "phit");
	// printf("obj.type = %d\n", hitobj->type);
	if (hitobj->type == 0)
		hitobj->nhit = normalize(sub(hitobj->phit, hitobj->sp.c));
	else if (hitobj->type == 1)
		hitobj->nhit = hitobj->pl.n;
	else if (hitobj->type == 2)
		hitobj->nhit = hitobj->sq.n;
	else if (hitobj->type == 3)
	{
		m = dot_2(ray.dir, hitobj->cy.n) * t + dot_2(sub(ray.orig, hitobj->cy.p), hitobj->cy.n);
		hitobj->nhit = normalize(sub(sub(hitobj->phit, hitobj->cy.p), mul(hitobj->cy.n, m)));
		// print_point(hitobj->phit, "phit");
		// print_point(hitobj->nhit, "nhit");
	}
	else if (hitobj->type == 4)
		hitobj->nhit = normalize(mul(hitobj->tr.n, -1));
}

// t_point	mix(t_point a, t_point b, double patt)
// {
// 	return (sum(mul(a, fill_p_1(1 - patt)), \
// 			mul(b, fill_p_1(patt))));
// }

static void		get_light_data(t_light *l, t_shapes hitobj)
{
	l->dir = sub(hitobj.phit, l->p); //direz
	// print_point(l->dir, "l->dir");
	// print_clr(l->clr, "l->clr");
	// printf("l->rat = %f\n", l->rat);
	l->intensity = clr_d_mul(l->clr, l->rat);
	l->dir = normalize(l->dir);
	l->shray.orig = sum(hitobj.phit, mul(l->dir, -BIAS));
	// print_point(l->shray.orig, "lray.orig");
	l->shray.dir = normalize(mul(l->dir, -1));
	// print_point(l->shray.dir, "lray.dir");
}

t_color		compute_clr(t_shapes o, t_light l, double fratio, double shad)
{
	t_color clr;
	
	clr = mix_clr(l.clr, o.objclr, l.rat * fratio * shad);
	// print_clr(clr, "clr");
	return (clr);
}

t_color			cast_ray(t_ray *ray, t_setting set, t_objects obj) //da riscrivere
{
	//t_coord	tex; //coordinate della texture
	double t; // distanza ray.orig - oggetto
	t_color ambcolor;
	t_color hitcolor; //colore nel puntixel colpito dal raggio
	float fratio = 1;
	t_shapes hitobj, hitobj2;
	t_uint shadow = 0;
	t_light *tmp = obj.lhead;

	// hitobject = fill_p_1(255); //colore oggetto
	hitcolor = fill_clr_3(0, 0, 0); //colore di sfondo
	// printf("******************************************\n");
	if (trace(ray, &obj, &t, &hitobj)) //se c'è un intersezione con un oggetto
	{
		ambcolor = mix_clr(set.amblclr, hitobj.objclr, 1);
		// print_clr(ambcolor, "ambcolor");
		get_surface_data(*ray, t, &hitobj);
		while (tmp)
		{
			// printf("t1 = %f\n", t);
			// print_point(ray->dir, "ray.dir");
			get_light_data(tmp, hitobj);
			// print_clr(hitobj.objclr, "clr");
			shadow = trace(&(tmp->shray), &obj, &t, &hitobj2) ? 0 : 1;
			if ((t > point_dist(hitobj.phit, tmp->p)))
				shadow = 1;
			if (point_dist(hitobj.phit, tmp->p) - t < 1e-03)
				shadow = 1;
			// print_point(sum(tmp->shray.orig, mul(tmp->shray.dir, t)), "phit3");
			// printf("t = %f\ndist = %f\n", t, point_dist(hitobj.phit, tmp->p));
			// printf("s = %u\n", shadow);
			// print_point(hitobj.nhit, "nhit"); print_point(tmp->dir, "tmp->dir");
			fratio = dot_2(hitobj.nhit, tmp->shray.dir);
			fratio = (fratio < 0) ? 0 : fratio;
			// print_point(ray->dir, "dir");
			// print_point(normalize(mul(ray->dir, fill_p_1(-1))), "-dir");
			// printf ("fratio = %f, obj = %d\n", fratio, hitobj.type);
			// print_clr(hitcolor, "hitcolor1");
			hitcolor = clr_sum(hitcolor, compute_clr(hitobj, *tmp, fratio, shadow));
			// print_clr(hitcolor, "hitcolor2");
			tmp = tmp->next;
		}
		hitcolor = clr_sum(ambcolor, hitcolor);
		// printf("****************\n");
		hitcolor = max_clr(hitcolor, hitobj.objclr);
	}
	// printf("t2 = %f\n", t);
	// printf("hit.r = %u, hit.g = %u, hit.b = %u\n", hitcolor.r, hitcolor.g, hitcolor.b);
	return (hitcolor);
}