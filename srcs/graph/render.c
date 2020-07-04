/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:07:40 by fmanetti          #+#    #+#             */
/*   Updated: 2020/07/03 10:29:46 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//The main render function. This where we iterate over all pixels in the image, generate
// primary rays and cast these rays into the scene. The content of the framebuffer is
// saved to a file.

void	render(float camtowrld[4][4], t_ray *ray, t_setting *set, t_objects obj)
{
	t_color *framebuffer; //array dove metto tutti i dati raccolti 
	t_color *pix;
	t_uint j;
	t_uint i;

	if (!(framebuffer = malloc((set->width * set->heigth) * sizeof(t_color))))
		return ;
	pix = framebuffer;
	/* moltiplicazione punto-matrice per trasformare l'origine usando la matrice 
	camera-to-world*/
	// camtowrld_set() funzione da utilizzare per trasformare la camera
	mult_pt_mtx(ray->orig, camtowrld, ray->orig);
	j = 0;
	// printf("1dir.z = %f\n", ray->dir.z);
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
			ray->dir.z = -1;
			// printf("2dir.z = %f\n", ray->dir.z);
			mult_vec_mtx(ray->dir, camtowrld, ray->dir);
			// printf("3dir.z = %f\n", ray->dir.z);
			ray->dir = normalize(ray->dir);
			// printf("4dir.z = %f\n", ray->dir.z);
			*(pix++) = cast_ray(ray, *set, obj); //provare con framebuffer
			i++;
		}
		j++;
	}
	draw(framebuffer, set);
}