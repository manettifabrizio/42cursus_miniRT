/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:19:02 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/04 13:12:01 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static void		get_surface_data(t_ray ray, double t, t_shapes *hitobj)
{
	hitobj->phit = vec_sum(ray.orig, point_mul(ray.dir, t));
	// print_point(hitobj->phit, "phit");
	// printf("obj.type = %d\n", hitobj->type);
	if (hitobj->type == 0)
		hitobj->nhit = normalize(vec_sub(hitobj->phit, hitobj->sp.c));
	else if (hitobj->type == 1)
		hitobj->nhit = hitobj->pl.n;
}

// t_point	mix(t_point a, t_point b, double patt)
// {
// 	return (vec_sum(point_mul(a, fill_point_1(1 - patt)), \
// 			point_mul(b, fill_point_1(patt))));
// }

static void		get_light_data(double t, t_light *l, t_shapes hitobj)
{
	l->dir = vec_sub(hitobj.phit, vec_sum(l->p, fill_point_1(BIAS))); //direz
	l->intensity = clr_mul(l->clr, l->rat / (4 * M_PI * norm(l->dir)));
	l->dir = normalize(l->dir);
	l->shray.orig = vec_sum(hitobj.phit, point_mul(l->dir, -BIAS));
	l->shray.dir = normalize(point_mul(l->dir, -1));
}

t_color			cast_ray(t_ray *ray, t_setting set, t_objects obj) //da riscrivere
{
	//t_coord	tex; //coordinate della texture
	double t; // distanza ray.orig - oggetto
	t_color hitcolor; //colore nel puntixel colpito dal raggio
	float fratio = 1;
	t_shapes hitobj, hitobj2;
	t_uint shadow = 1;
	t_light *tmp = obj.lhead;

	// hitobject = fill_point_1(255); //colore oggetto
	hitcolor = set.amblclr; //colore di sfondo
	// printf("******************************************\n");
	if (trace(ray, &obj, &t, &hitobj)) //se c'è un intersezione con un oggetto
	{
		while (tmp)
		{
		// printf("t1 = %f\n", t);
		// printf("hitobj.x = %f\n", hitobj.sp.c.x);
			get_surface_data(*ray, t, &hitobj);
			// print_point(ray->dir, "ray.dir");
			get_light_data(t, tmp, hitobj);
			// print_clr(hitobj.objclr, "clr");
			shadow = trace(&(tmp->shray), &obj, &t, &hitobj2) ? 0 : 1;
			if (t > point_dist(hitobj.phit, tmp->p))
				shadow = 1;
			// print_point(vec_sum(tmp->shray.orig, point_mul(tmp->shray.dir, t)), "phit3");
			// printf("t = %f\ndist = %f\n", t, point_dist(hitobj.phit, tmp->p));
			// printf("s = %u\n", shadow);
			// print_point(hitobj.nhit, "nhit"); print_point(tmp->dir, "tmp->dir");
			fratio = dot_2(hitobj.nhit, tmp->shray.dir);
			tmp = tmp->next;
		}
		// print_point(ray->dir, "dir");
		// print_point(normalize(point_mul(ray->dir, fill_point_1(-1))), "-dir");
		// printf ("fratio = %f, obj = %d\n", fratio, hitobj.type);
		// print_clr(tmp->intensity, "light intensity");
		if (fratio > 0)
			hitcolor = clr_mul(hitobj.objclr, fratio * shadow);
		if (fratio < 0)
			hitcolor = fill_clr_3(0,0,0);
	}
	// printf("t2 = %f\n", t);
	// printf("hit.r = %u, hit.g = %u, hit.b = %u\n", hitcolor.r, hitcolor.g, hitcolor.b);
	return (hitcolor);
}