/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:07:40 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/26 10:19:59 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//The main render function. This where we iterate over all pixels in the image, generate
// primary rays and cast these rays into the scene. The content of the framebuffer is
// saved to a file.

void	render(float camtowrld[4][4], t_ray *ray, t_setting *set, t_shapes sh)
{
	t_point framebuffer[set->width * set->heigth]; //array dove metto tutti i dati raccolti 
	t_point *pix;
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
			ray->dir.x = (2 * ((i + 0.5) / set->width) - 1) \
				* set->scale * set->imageAR; //moltiplicare per AR per assicurarsi che i pixel siano quadrati
			ray->dir.y = (1 - 2 * ((j + 0.5) / set->heigth)) \
				* set->scale; //moltiplicare per il field of view
			mult_vec_mtx(ray->dir, camtowrld, ray->dir);
			ray->dir = normalize(ray->dir);
			*(pix++) = cast_ray(ray, sh); //provare con framebuffer
			i++;
		}
		j++;
	}
	draw(framebuffer, set);
}