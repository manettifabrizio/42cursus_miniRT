/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:15:54 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/26 21:41:33 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		color(t_uint x, t_uint y, t_setting *set, t_color f)
{
	int pixel;

	pixel = (x + (y * set->width)) * 4;
	(set->d.clr)[pixel] = (char)f.b;
	(set->d.clr)[pixel + 1] = (char)f.g;
	(set->d.clr)[pixel + 2] = (char)f.r;
	(set->d.clr)[pixel + 3] = (char)0;
}

int				draw(t_color *clr, t_setting set, t_objects obj)
{
	int		x;
	int		y;
	int		i;
	t_hook	h;

	h.set = set;
	h.obj = obj;
	y = -1;
	i = -1;
	while (++y < set.heigth)
	{
		x = -1;
		while (++x < set.width)
			color(x, y, &set, clr[++i]);
	}
	mlx_put_image_to_window(set.d.mlx, set.d.win, set.d.img, 0, 0);
	mlx_hook(set.d.win, 17, 0, close_hook, &(set.d));
	mlx_key_hook(set.d.win, key_hook, &(h));
	if (set.save == 1)
		create_bmp(set.d.clr, set.width, set.heigth);
	else
		mlx_loop(set.d.mlx);
	return (1);
}
