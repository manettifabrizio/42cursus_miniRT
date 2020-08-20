/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:15:54 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/20 11:33:43 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

// static void		color(char *id, t_color *framebuffer, t_setting *set)
// {
// 	t_uint x, y;
// 	t_uint 	i;


// 	i = 0;
// 	// if (!(clr = malloc((set->width * set->heigth * 4) * sizeof(char*))))
// 	// 	return (NULL);
// 	x = 0;
// 	while (x < set->heigth)
// 	{
// 		y = 0;
// 		while (y < set->width)
// 		{
// 			id[(x + (y * set->width)) * 4] = (char)framebuffer[y].b;
// 			id[(x + (y * set->width)) * 4 + 1] = (char)framebuffer[y].g;
// 			id[(x + (y * set->width)) * 4 + 2] = (char)framebuffer[y].r;
// 			y++;
// 		}
// 		//rgb to int rgb
// 		// clr[i] = (t_uint)(framebuffer[i].r);
// 		// clr[i] = (clr[i] << 8) + (t_uint)(framebuffer[i].g);
// 		// clr[i] = (clr[i] << 8) + (t_uint)(framebuffer[i].b);
// 		// clr[i] = (t_uint)(255 * framebuffer[i].x);
// 		// clr[i] = (clr[i] << 8) + (t_uint)(255 * framebuffer[i].y);
// 		// clr[i] = (clr[i] << 8) + (t_uint)(255 * framebuffer[i].z);
// 		//printf("clr[%u] = %u\n", i, clr[i]);
// 		i++;
// 		x++;
// 	}
// 	printf("clr = %s\n", id);
// }

static void		color(t_uint x, t_uint y, t_setting *set, t_color f)
{
	int pixel;

	pixel = (x + (y * set->width)) * 4;
    (set->d.clr)[pixel] = (char)f.b;
    (set->d.clr)[pixel + 1] = (char)f.g;
    (set->d.clr)[pixel + 2] = (char)f.r;
	(set->d.clr)[pixel + 3] = (char)0;
	// printf("x + y = %d\n", x + y);
	// printf("b = %d, g = %d, r = %d\n", f.b, f.g, f.r);
}

int				draw(t_color *framebuffer, t_setting *set)
{
	int x;
	int y;
	int i;

	y = -1;
	i = -1;
	while (++y < set->heigth)
	{
		x = -1;
		while (++x < set->width)
		{
			color(x, y, set, framebuffer[++i]);
			printf("x = %d, y = %d, i = %d\n", x, y, i);
		}
	}
	mlx_put_image_to_window(set->d.mlx, set->d.win, set->d.img, 0, 0);
	mlx_hook(set->d.win, 17, 0, close_hook, &(set->d));
	mlx_key_hook(set->d.win, key_hook, &(set->d));
	mlx_loop(set->d.mlx);
	return (1);
}