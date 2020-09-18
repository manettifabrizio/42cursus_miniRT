/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:07:40 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/18 21:15:45 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static	void	compute_raydir(t_ray *ray, t_objects obj)
{
	ray->orig = obj.ctmp->p;
	ray->dir.z = -1;
	ray->dir = normalize(ray->dir);
	ray->dir = compute_rot(ray->dir, obj.ctmp->cx, fill_p(1, 0, 0));
	ray->dir = compute_rot(ray->dir, obj.ctmp->cy, fill_p(0, 1, 0));
}

void	render(t_ray *ray, t_setting *set, t_objects obj)
{
	t_color *clr; //array dove metto tutti i dati raccolti 
	t_color *pix;
	t_uint j;
	t_uint i;

	if (!(clr = malloc((set->width * set->heigth) * sizeof(t_color))))
		return ;
	pix = clr;
	j = -1;
	while (++j < set->heigth)
	{
		i = -1;
		while (++i < set->width) 
		{
			ray->dir.x = (2 * ((i + 0.5) / set->width) - 1)
				* set->scale * set->imageAR;
			ray->dir.y = (1 - 2 * ((j + 0.5) / set->heigth))
				* set->scale;
			compute_raydir(ray, obj);
			*(pix++) = cast_ray(ray, *set, obj);
		}
	}
	draw(clr, set, obj);
}