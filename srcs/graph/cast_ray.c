/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:19:02 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/25 12:05:45 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

// static void	get_surface_data(t_point *phit, t_point *nhit, t_shapes sh)
// {
// 	*nhit = vec_sub(*phit, sh.shead->sp.c); //calcolo la normale
// 	*nhit = normalize(*nhit);
// 	// In this particular case, the normal is simular to a point on a unit sphere
// 	// centred around the origin. We can thus use the normal coordinates to compute
// 	// the spherical coordinates of Phit.
// 	// atan2 returns a value in the range [-pi, pi] and we need to remap it to range [0, 1]
// 	// acosf returns a value in the range [0, pi] and we also need to remap it to the range [0, 1]
// }

t_point	mix(t_point a, t_point b, float patt)
{
	return (vec_sum(point_mul(a, fill_point_1(1 - patt)), \
			point_mul(b, fill_point_1(patt))));
}

t_color clr_mul(t_color clr, float x)
{
	t_color clr1;

	clr1.r = clr.r * x;
	clr1.g = clr.g * x;
	clr1.b = clr.b * x;
	return (clr1);
}

t_color	cast_ray(t_ray *ray, t_setting set, t_objects obj) //da riscrivere
{
	t_point phit; // punto di intersezione
	t_point nhit; // normale nel p di intersezione
	t_coord	tex; //coordinate della texture
	float pattern;
	float t; // distanza ray.orig - oggetto
	t_color hitcolor; //colore nel puntixel colpito dal raggio
	t_sphere	hitsp;
	float fratio;
	t_shapes hitobj;
	// t_point	hitobject; //puntatore verso l'oggetto colpito

	// hitobject = fill_point_1(255); //colore oggetto
	hitcolor = set.amblclr; //colore di sfondo
	if (trace(ray, &obj, &t, &hitobj)) //se c'è un intersezione con un oggetto
	{
		printf("t1 = %f\n", t);
		printf("hitobj.x = %f\n", hitobj.sp.c.x);
		// phit = vec_sum(ray->orig, point_mul(ray->dir, fill_point_1(t)));
		// get_surface_data(&phit, &nhit, hitobj);
		fratio = dot_2(hitobj.nhit, normalize(point_mul(ray->dir, fill_point_1(-1))));
		// print_point(nhit, "nhit"); 
		// print_point(ray->dir, "dir");
		// print_point(normalize(point_mul(ray->dir, fill_point_1(-1))), "-dir");
		// printf ("fratio = %f\n", fratio);
		hitcolor = (fratio > 0 ) ? clr_mul(hitobj.objclr, fratio) : hitcolor;
	}
	printf("t2 = %f\n", t);
	// printf("hit.r = %u, hit.g = %u, hit.b = %u\n", hitcolor.r, hitcolor.g, hitcolor.b);
	return (hitcolor);
}