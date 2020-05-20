/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:07:40 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/20 21:10:20 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"

float	*cast_ray(t_ray *ray, t_setting *set, t_uint depth)
{
	t_point hitcolor;
	t_point one;
	t_point divide;

	one = fill_point(1, 1, 1, one);
	hitcolor = (point_mult(point_sum(*(ray->dir), one)), fill_point(0.5, 0.5, 0.5, divide));
}

//The main render function. This where we iterate over all pixels in the image, generate
// primary rays and cast these rays into the scene. The content of the framebuffer is
// saved to a file.

void	render(float **camtowrld, t_ray *ray, t_setting *set)
{
	float framebuffer[set->width * set->heigth][3]; //array dove metto tutti i dati raccolti 
	float **pix;
	t_uint j;
	t_uint i;

	pix = framebuffer;
	/* moltiplicazione punto-matrice per trasformare l'origine usando la matrice 
	camera-to-world*/
	// camtowrld_set() funzione da utilizzare per trasformare la camera
	mult_pt_mtx(*(ray->orig), camtowrld, *(ray->orig));
	j = 0;
	while (j < set->heigth)
	{
		i = 0;
		while (i < set->width) 
		{						
			ray->dir->x = (2 * (i + 0.5) / set->width - 1) \ //raster space -> NDC space ->
				* set->scale * set->imageAR; //moltiplicare per AR per assicurarsi che i pixel siano quadrati
			ray->dir->y = (1 - 2 * (j + 0.5) / set->heigth) \
				* set->scale; //moltiplicare per il field of view
			mult_vec_mtx(*(ray->dir), camtowrld, *(ray->dir));
			*(ray->dir) = normalize(*(ray->dir));
			*(pix++) = cast_ray(ray, set, 0);
			i++;
		}
		j++;
	}
}