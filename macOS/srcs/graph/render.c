/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:07:40 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/07 16:54:54 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		charging_bar(int x, int y, t_setting set, t_objects obj)
{
	int n;

	x += (set.width * y);
	n = ((set.width - 1) * (set.heigth - 1)) / 100;
	if (x % (int)n == 0)
	{
		ft_putstr("\rRendering... ");
		ft_putstr("Cam (");
		ft_putnbr(obj.ntmp + 1);
		ft_putchar('/');
		ft_putnbr(obj.nc);
		ft_putstr(") [");
		ft_putnbr(x / n);
		ft_putstr("%]");
	}
	if (x == (set.width * set.heigth - 1) && set.save == 0)
	{
		ft_putchar('\n');
		ft_putstr("[ miniRT ] Rendered \033[0;32mSuccessfully\n\033[0m");
		ft_putstr("Use SHIFT to change between cameras.\n");
		ft_putstr("Use ESC or Q to \033[0;31mEXIT\033[0m.\n");
	}
}

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
	int		y;
	int		x;
	t_color *tmp;

	compute_rot_mtx(&set, obj);
	if (!(set.mlx.rgbclr = malloc((set.width * set.heigth) * sizeof(t_color))))
		return ;
	tmp = set.mlx.rgbclr;
	y = -1;
	while (++y < set.heigth)
	{
		x = -1;
		while (++x < set.width)
		{
			ray->dir.x = (2 * ((x + 0.5) / set.width) - 1)
				* obj.ctmp->scale * set.imagear;
			ray->dir.y = (1 - 2 * ((y + 0.5) / set.heigth))
				* obj.ctmp->scale;
			compute_raydir(ray, set, obj);
			*(tmp++) = cast_ray(*ray, set, obj);
			charging_bar(x, y, set, obj);
		}
	}
	draw(set.mlx.rgbclr, set, obj);
}
