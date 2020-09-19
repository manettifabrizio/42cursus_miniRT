/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:07:40 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 20:30:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		compute_raydir(t_ray *ray, t_setting set, t_objects obj)
{
	ray->orig = obj.ctmp->p;
	ray->dir.z = -1;
	ray->dir = normalize(ray->dir);
	ray->dir = normalize(mult_vec_mtx(ray->dir, set.xmtx));
	ray->dir.y *= set.inversex;
	ray->dir = normalize(mult_vec_mtx(ray->dir, set.ymtx));
	ray->dir.y *= set.inversey;
}

static void		compute_rot_mtx(t_setting *set, t_objects obj)
{
	set->inversex = 1;
	set->inversey = 1;
	set->xmtx = compute_rot(obj.ctmp->cx, fill_p(1, 0, 0), set);
	set->ymtx = compute_rot(obj.ctmp->cy, fill_p(0, 1, 0), set);
}

void			render(t_ray *ray, t_setting set, t_objects obj)
{
	int		j;
	int		i;
	t_color *clr;
	t_color *pix;

	compute_rot_mtx(&set, obj);
	if (!(clr = malloc((set.width * set.heigth) * sizeof(t_color))))
		return ;
	pix = clr;
	j = -1;
	while (++j < set.heigth)
	{
		i = -1;
		while (++i < set.width)
		{
			ray->dir.x = (2 * ((i + 0.5) / set.width) - 1)
				* obj.ctmp->scale * set.imagear;
			ray->dir.y = (1 - 2 * ((j + 0.5) / set.heigth))
				* obj.ctmp->scale;
			compute_raydir(ray, set, obj);
			*(pix++) = cast_ray(ray, set, obj);
		}
	}
	draw(clr, set, obj);
}
