/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:07:40 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/23 11:07:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	get_surface_data(t_point *phit, t_point *nhit, t_coord *tex, t_sphere sp)
{
	*nhit = vector_sub(*phit, sp.ctr); //calcolo la normale
	normalize(*nhit);
	// In this particular case, the normal is simular to a point on a unit sphere
	// centred around the origin. We can thus use the normal coordinates to compute
	// the spherical coordinates of Phit.
	// atan2 returns a value in the range [-pi, pi] and we need to remap it to range [0, 1]
	// acosf returns a value in the range [0, pi] and we also need to remap it to the range [0, 1]
	tex->x1 = (1 + atan2(nhit->z, nhit->x) / M_PI) * 0.5;
    tex->x2 = acosf(nhit->y) / M_PI;
}

int		trace(const t_ray *ray, t_sphere sp, float *tnear, t_color *hitobject)
{
	t_uint x;
	t_uint objnum = 1;
	float t;

	x = 0;
	*tnear = F_LIMIT;
	while (x < objnum)
	{
		t = F_LIMIT;
		if (intersect(*ray, sp, &t) && t < *tnear)
		{
			hitobject++;
			*tnear = t;
		}
		x++;
	}
	return (1);
}

t_color	cast_ray(t_ray *ray, t_sphere sp)
{
	t_point one;
	t_point divide;
	t_point tmp;
	t_color hitcolor;
	float t; // distanza ray.orig - oggetto
	t_point phit; // punto di intersezione
	t_point nhit; // normale nel p di intersezione
	t_coord	tex; //coordinate della texture
	float pattern;
	t_color	hitobject;

	hitcolor.r = 0;
	hitcolor.g = 0;
	hitcolor.b = 0;
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	one.x = 0;
	divide.x = 0;
	if (trace(ray, sp, &t, &hitobject))
	{
		phit = vector_sum(ray->orig, point_mul(ray->dir, fill_point(t, t, t, tmp)));
		one = fill_point(1, 1, 1, one);
		get_surface_data(&phit, &nhit, &tex, sp);
		pattern = (fmodf(tex.x1 * 4, 1) > 0.5) ^ (fmodf(tex.x2 * 4, 1) > 0.5); //??????????
		tmp = (point_mul(vector_sum(ray->dir, one), fill_point(0.5, 0.5, 0.5, divide)));
		hitcolor.r = tmp.x;
		hitcolor.g = tmp.y;
		hitcolor.b = tmp.z;
	}
	return (hitcolor);
}

//The main render function. This where we iterate over all pixels in the image, generate
// primary rays and cast these rays into the scene. The content of the framebuffer is
// saved to a file.

void	render(float camtowrld[4][4], t_ray *ray, t_setting *set, t_sphere sp)
{
	t_color framebuffer[set->width * set->heigth]; //array dove metto tutti i dati raccolti 
	t_color *pix;
	t_uint j;
	t_uint i;

	pix = framebuffer;
	/* moltiplicazione punto-matrice per trasformare l'origine usando la matrice 
	camera-to-world*/
	// camtowrld_set() funzione da utilizzare per trasformare la camera
	mult_pt_mtx(ray->orig, camtowrld, ray->orig);
	j = 0;
	while (j < set->heigth)
	{
		i = 0;
		while (i < set->width) 
		{
			//raster space -> NDC space ->
			ray->dir.x = (2 * (i + 0.5) / set->width - 1) \
				* set->scale * set->imageAR; //moltiplicare per AR per assicurarsi che i pixel siano quadrati
			ray->dir.y = (1 - 2 * (j + 0.5) / set->heigth) \
				* set->scale; //moltiplicare per il field of view
			mult_vec_mtx(ray->dir, camtowrld, ray->dir);
			ray->dir = normalize(ray->dir);
			*(pix++) = cast_ray(ray, sp); //provare con framebuffer
			i++;
		}
		j++;
	}
}