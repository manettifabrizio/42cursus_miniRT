/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:15:54 by fmanetti          #+#    #+#             */
/*   Updated: 2020/07/03 11:16:15 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static t_uint 	*color(t_color *framebuffer, t_setting *set)
{
	t_uint 	i;
	t_uint	*clr;
	
	i = 0;
	if (!(clr = malloc(set->width * set->heigth * sizeof(char*))))
		return (NULL);
	while (i < (set->width * set->heigth))
	{ //rgb to int rgb
		clr[i] = (t_uint)(framebuffer[i].r);
		clr[i] = (clr[i] << 8) + (t_uint)(framebuffer[i].g);
		clr[i] = (clr[i] << 8) + (t_uint)(framebuffer[i].b);
		// clr[i] = (t_uint)(255 * framebuffer[i].x);
		// clr[i] = (clr[i] << 8) + (t_uint)(255 * framebuffer[i].y);
		// clr[i] = (clr[i] << 8) + (t_uint)(255 * framebuffer[i].z);
		//printf("clr[%u] = %u\n", i, clr[i]);
		i++;
	}
	return (clr);
}

int				draw(t_color *framebuffer, t_setting *set)
{
	void	*mlx;
	void	*win;
	t_uint	*clr;
	t_uint	x;
	t_uint	y;
	t_uint	i = 0;

	if (!(mlx = mlx_init()))
		return 0;
	//printf("mlx = %p\n", mlx);
	if (!(win = mlx_new_window(mlx, set->width, set->heigth, "Sphere")))
		return (0); //distruggere la finestra
	clr = color(framebuffer, set);
	y = 0;
	while (y < set->heigth)
	{
		x = 0;
		while (x < (set->width))
		{
			mlx_pixel_put(mlx, win, x, y, clr[i]);
			i++;
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
	return (1);
}