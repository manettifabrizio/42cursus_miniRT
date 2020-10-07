/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:15:54 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/07 17:02:39 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		mlx_draw(t_setting set, t_hook h)
{
	mlx_put_image_to_window(set.mlx.mlx, set.mlx.win, set.mlx.img, 0, 0);
	mlx_key_hook(set.mlx.win, key_hook, &h);
	mlx_hook(set.mlx.win, 17, 1L << 17, close_hook, &(set.mlx));
	mlx_loop(set.mlx.mlx);
}
static void		color(t_uint x, t_uint y, t_setting *set, t_color f)
{
	int pixel;

	pixel = (x + (y * set->width)) * 4;
	(set->mlx.clr)[pixel] = (char)f.b;
	(set->mlx.clr)[pixel + 1] = (char)f.g;
	(set->mlx.clr)[pixel + 2] = (char)f.r;
	(set->mlx.clr)[pixel + 3] = (char)0;
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
	if (set.save == 0)
		mlx_draw(set, h);
	else
		create_bmp(set.mlx.clr, set.width, set.heigth);
	return (1);
}
