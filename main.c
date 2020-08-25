/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:08:20 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/24 10:19:06 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"

void	print_sp(const t_shapes shapes)
{
	printf("c.x = %f\n", shapes.sp.c.x);
	printf("c.y = %f\n", shapes.sp.c.y);
	printf("c.z = %f\n", shapes.sp.c.z);
	printf("d = %f\n", shapes.sp.diam);
	printf("clr.r = %u\n", shapes.sp.clr.r);
	printf("clr.g = %u\n", shapes.sp.clr.g);
	printf("clr.b = %u\n", shapes.sp.clr.b);
	printf("++++++++++++++++++++++++++++++++++++++++\n");
}

void	print_parse(t_setting set, t_objects *obj)
{
	printf ("heigth = %u\nwidth = %u\nscale = %f\nambience ratio = %f\namb r = %u, amb g = %u, amb b = %u\n", set.heigth, set.width, set.scale, set.amblrat, set.amblclr.r, set.amblclr.g, set.amblclr.b);
	int x;
	// printf("x = %u\n", obj->ns);
	x = obj->ns;
	t_shapes *tmp;
	// printf("shead = %p\n", obj->shead);
	tmp = obj->shead;
	// printf("shead = %p\n", tmp);
	while (tmp != NULL)
	{
		printf("tmp.p = %p\n", tmp);
		print_sp(*(tmp));
		//sp_intersect(ray, *obj.sp, t);
		tmp = tmp->next;
	}
}

static void		initiate_window(t_setting *set)
{
	if (!(set->d.mlx = mlx_init()))
		mlx_error(set->d);
	if (!(set->d.win = mlx_new_window(set->d.mlx, set->width, set->heigth, "miniRT")))
		mlx_error(set->d);
	if (!(set->d.img = mlx_new_image(set->d.mlx, set->width, set->heigth)))
		mlx_error(set->d);
	if (!(set->d.clr = mlx_get_data_addr(set->d.img, &(set->d.bpp), &(set->d.sz_line), 
						&(set->d.endian))))
		mlx_error(set->d);
}

int		main(int ac, char **av)
{
	float	camtowrld[4][4];
	t_ray		ray;
	t_setting	set;
	t_objects	obj;
	
	if (ac < 2)
	{
		ft_putstr("\033[0;31mError\033[0m : Less than two arguments\n");
		return (0);
	}
	start(camtowrld, &ray, &set, &obj);
	start_parse(av, &set, &obj);
	initiate_window(&set);
	// print_parse(set, &obj);
	ray.orig = obj.chead->c;
	// print_point(ray.orig);
	// printf("tmp.c.x = %f\n", obj.chead->c.x);
	// print_point(obj.chead->c);
	// ray.dir = obj.chead->v;
	render(camtowrld, &ray, &set, obj);
	return (0);
}