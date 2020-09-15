/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:07:40 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/15 18:24:33 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//The main render function. This where we iterate over all pixels in the image, generate
// primary rays and cast these rays into the scene. The content of the framebuffer is
// saved to a file.

t_point			cal_pix(t_objects obj, t_uint j, t_uint i, t_setting set)
{
	t_point pix;

	float pw = 2 * tan((float)obj.chead->alpha / 360 * M_PI) / set.width * set.imageAR;
	float ph = 2 * tan((float)obj.chead->alpha / 360 * M_PI) / set.heigth;
	pix = sum(obj.chead->p, sub(obj.chead->cz, mul(obj.chead->cx, pw * (1000 / 2))));
	pix = sum(pix, mul(obj.chead->cy, (1000 / 2) * ph));
	pix = sum(pix, mul(obj.chead->cx, pw / 2));
	pix = sub(pix, mul(obj.chead->cy, ph / 2));
	pix = sum(pix, mul(obj.chead->cx, pw * i));
	pix = sub(pix, mul(obj.chead->cy, ph * j));
	return (pix);
}

void	render(t_ray *ray, t_setting *set, t_objects obj)
{
	t_color *framebuffer; //array dove metto tutti i dati raccolti 
	t_color *pix;
	t_uint j = 100;
	t_uint i = 200;
	float x, y;

	if (!(framebuffer = malloc((set->width * set->heigth) * sizeof(t_color))))
		return ;
	pix = framebuffer;
	/* moltiplicazione punto-matrice per trasformare l'origine usando la matrice 
	camera-to-world*/
	// camtowrld_set() funzione da utilizzare per trasformare la camera
	// mult_pt_mtx(ray->orig, camtowrld, ray->orig);
	// printf("cam.c.x = %f\ncam.c.y = %f\ncam.c.z = %f\n", ray->orig.x, ray->orig.y, ray->orig.z);
	// printf("1dir.z = %f\n", ray->dir.z);
	// print_point(ray->orig);
	j = 0;
	while (j < set->heigth)
	{
		i = 0;
		while (i < set->width) 
		{
			ray->dir.x = (2 * ((i + 0.5) / set->width) - 1)
				* set->scale * set->imageAR; //moltiplicare per AR per assicurarsi che i pixel siano quadrati
			ray->dir.y = (1 - 2 * ((j + 0.5) / set->heigth))
				* set->scale; //moltiplicare per il field of view
			ray->dir.z = -1;
			// print_point(normalize(ray->dir), "ray->dir 1");
			ray->dir = normalize(ray->dir);
			// ray->dir = normalize(sub(ray->dir, ray->orig));
			// ray->dir = normalize(sub(obj.chead->p, normalize(ray->dir)));
			// ray->dir = normalize(sub(obj.chead->p, cal_pix(obj, j, i, *set)));
			// if (obj.chead->n.x != 0)
				ray->dir = compute_rot(ray->dir, obj.chead->cx, fill_p(1, 0, 0));
			// // if (obj.chead->n.y != 0)
				ray->dir = compute_rot(ray->dir, obj.chead->cy, fill_p(0, 1, 0));
			// if (obj.chead->n.z != 0)
				// ray->dir = compute_rot(ray->dir, obj.chead->cz, fill_p(0, 0, 1));
			// print_point(ray->dir, "ray->dir 2");
			// if (obj.chead->cz.x == 0 && obj.chead->cz.y == 0 && obj.chead->cz.z == -1)
			// 	ray->dir.y *= -1;
			*(pix++) = cast_ray(ray, *set, obj); //provare con framebuffer
			i++;
		}
		j++;
	}
	draw(framebuffer, set);
}