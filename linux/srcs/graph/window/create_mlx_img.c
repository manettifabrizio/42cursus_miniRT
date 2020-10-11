/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:58:16 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/09 20:26:12 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		redraw(void *param)
{
	t_objects *obj;

	obj = param;
	mlx_put_image_to_window(obj->mlx.mlx, obj->mlx.win, obj->ctmp->img, 0, 0);
	return (1);
}

void	create_mlx_img(t_color *clr, t_setting set, t_objects *obj)
{
	int		x;
	int		y;
	int		i;
	int		pixel;

	y = -1;
	i = -1;
	while (++y < set.heigth)
	{
		x = -1;
		while (++x < set.width)
		{
			pixel = (x + (y * set.width)) * 4;
			(obj->ctmp->clr)[pixel] = (char)clr[++i].b;
			(obj->ctmp->clr)[pixel + 1] = (char)clr[i].g;
			(obj->ctmp->clr)[pixel + 2] = (char)clr[i].r;
			(obj->ctmp->clr)[pixel + 3] = (char)0;
		}
	}
	if (set.save == 1)
		create_bmp(obj->chead->clr, set.width, set.heigth);
	free(clr);
}
