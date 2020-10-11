/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 00:07:59 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/09 20:25:46 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		print_render_success(void)
{
	ft_putstr("[ miniRT ] Rendered \033[0;32mSuccessfully\n\033[0m");
	ft_putstr("Use SHIFT to change between cameras.\n");
	ft_putstr("Use ESC or Q to \033[0;31mEXIT\033[0m.\n");
}

static void		val_init(t_objects *obj, t_setting *set)
{
	obj->nc = 0;
	obj->chead = NULL;
	obj->nl = 0;
	obj->lhead = NULL;
	obj->ns = 0;
	obj->shead = NULL;
	obj->ntmp = 0;
	set->save = 0;
	set->width = -1;
	set->heigth = -1;
	set->amblrat = -1;
}

static void		start(int ac, char **av, t_objects *obj, t_setting *set)
{
	val_init(obj, set);
	start_errors(ac, av);
	if (ac > 2 && (ft_strcmp(av[2], "-save") == 0))
		set->save = 1;
}

static void		initiate_window(t_setting set, t_objects *obj, t_uint x)
{
	if (x == 0)
	{
		if (!(obj->mlx.mlx = mlx_init()))
			mlx_error(obj->mlx, obj, 0);
		if (set.save == 0)
			if (!(obj->mlx.win = mlx_new_window(obj->mlx.mlx, set.width,
			set.heigth, "miniRT")))
				mlx_error(obj->mlx, obj, 0);
	}
	else
	{
		if (!(obj->ctmp->img = mlx_new_image(obj->mlx.mlx, set.width,
		set.heigth)))
			mlx_error(obj->mlx, obj, 1);
		if (!(obj->ctmp->clr = mlx_get_data_addr(obj->ctmp->img,
		&(obj->mlx.bpp), &(obj->mlx.sz_line), &(obj->mlx.endian))))
			mlx_error(obj->mlx, obj, 1);
	}
}

int				main(int ac, char **av)
{
	t_ray		ray;
	t_setting	set;
	t_objects	obj;

	start(ac, av, &obj, &set);
	parse(av, &set, &obj);
	initiate_window(set, &obj, 0);
	obj.ctmp = obj.chead;
	while (obj.ntmp < obj.nc)
	{
		ray.orig = obj.ctmp->p;
		initiate_window(set, &obj, 1);
		render(&ray, set, &obj);
		obj.ntmp++;
		obj.ctmp = obj.ctmp->next;
	}
	print_render_success();
	obj.ntmp = 0;
	obj.ctmp = obj.chead;
	mlx_put_image_to_window(obj.mlx.mlx, obj.mlx.win, obj.chead->img, 0, 0);
	mlx_expose_hook(obj.mlx.win, redraw, &obj);
	mlx_key_hook(obj.mlx.win, key_hook, &obj);
	mlx_hook(obj.mlx.win, 17, 1L << 17, close_hook, &(obj.mlx));
	mlx_loop(obj.mlx.mlx);
	return (0);
}
