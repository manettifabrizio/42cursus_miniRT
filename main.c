/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:08:20 by fmanetti          #+#    #+#             */
/*   Updated: 2020/06/22 13:29:51 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"

void	print_sp(const t_shapes shapes)
{
	printf("c.x = %f\n", shapes.sp.c.x);
	printf("c.y = %f\n", shapes.sp.c.y);
	printf("c.z = %f\n", shapes.sp.c.z);
	printf("d = %f\n", shapes.sp.d);
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

int		main(int ac, char **av)
{
	float	camtowrld[4][4];
	t_ray		ray;
	t_setting	set;
	t_objects	obj;

	if (ac < 2)
	{
		perror("Error: ");
		return (0);
	}
	// sp1.diam = 2;
	// sp2.diam = 0.5;
	set.width = 1000;
	set.heigth = 900;
	start(camtowrld, &ray, &set, &obj);
	start_parse(av, &set, &obj);
	print_parse(set, &obj);
	//render(camtowrld, &ray, &set, obj);
	return (0);
}