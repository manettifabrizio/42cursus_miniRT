/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:19:02 by fmanetti          #+#    #+#             */
/*   Updated: 2020/07/03 10:27:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	get_surface_data(t_point *phit, t_point *nhit, t_coord *tex, t_objects sh)
{
	*nhit = vector_sub(*phit, sh.shead->sp.c); //calcolo la normale
	normalize(*nhit);
	// In this particular case, the normal is simular to a point on a unit sphere
	// centred around the origin. We can thus use the normal coordinates to compute
	// the spherical coordinates of Phit.
	// atan2 returns a value in the range [-pi, pi] and we need to remap it to range [0, 1]
	// acosf returns a value in the range [0, pi] and we also need to remap it to the range [0, 1]
	tex->x1 = (1 + atan2(nhit->z, nhit->x) / M_PI) * 0.5;
    tex->x2 = acosf(nhit->y) / M_PI;
}

t_point	mix(t_point a, t_point b, float patt)
{
	return (vector_sum(point_mul(a, fill_point_1(1 - patt)), \
			point_mul(b, fill_point_1(patt))));
}

t_color	cast_ray(t_ray *ray, t_setting set, t_objects obj) //da riscrivere
{
	t_point phit; // punto di intersezione
	t_point nhit; // normale nel p di intersezione
	t_coord	tex; //coordinate della texture
	float pattern;
	float t; // distanza ray.orig - oggetto
	t_color hitcolor; //colore nel puntixel colpito dal raggio
	// t_point	hitobject; //puntatore verso l'oggetto colpito

	// hitobject = fill_point_1(255); //colore oggetto
	hitcolor = set.amblclr; //colore di sfondo
	if (trace(ray, &obj, &t, &hitcolor)) //se c'è un intersezione con un oggetto
	{
		// phit = vector_sum(ray->orig, point_mul(ray->dir, fill_point_2(t)));
		// get_surface_data(&phit, &nhit, &tex, sh);
		// pattern = (fmodf(tex.x1 * 4, 1) > 0.5) ^ (fmodf(tex.x2 * 4, 1) > 0.5);
		// hitcolor = point_mul(fill_point_1(dot_product_1(ray->dir)), mix(hitobject, point_mul(hitobject, fill_point_1(0.8)), pattern));
		//^qui in qualche modo trasforma le coordinate della direzione del raggio in un colore
		//aggiungendovi uno e dividendole per 2
	}
	// printf("hit.r = %f, hit.g = %f, hit.b = %f\n", hitcolor.x, hitcolor.y, hitcolor.z);
	return (hitcolor);
}