/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:06:58 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/25 10:44:53 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

// void	print_sp(const t_objects sh)
// {
// 	printf("n = %d\n", sh.n);
// 	printf("c.x = %f\n", sh.sp.c.x);
// 	printf("c.y = %f\n", sh.sp.c.y);
// 	printf("c.z = %f\n", sh.sp.c.z);
// 	printf("d = %f\n", sh.sp.d);
// 	printf("clr.r = %u\n", sh.sp.clr.r);
// 	printf("clr.g = %u\n", sh.sp.clr.g);
// 	printf("clr.b = %u\n", sh.sp.clr.b);
// }

int		intersect(const t_ray ray, t_shapes *sh, float *t)
{
	// int 		x;
	// printf("x = %d\n", x);
	//printf("tmp.sp.c.z = %f\n", tmp->sp.c.z);
	// printf("*******\n");
	// print_point(ray.dir);
	// t_color *objcolor;
	// *objcolor = fill_clr_3(0,0,0);
	if (sh->num == 0)
		return (sp_intersect(ray, sh, t));
	// else if (sh->num == 1)
	// 	return (pl_intersect(ray, sh->pl, t, objcolor));
	// else if (sh->num == 2)
	//  	return (sq_intersect(ray, sh->sq, t, objcolor));
	// else if (sh->num == 3)
	//  	return (cy_intersect(ray, sh->cy, t, objcolor));
	// else if (sh->num == 4)
	// 	return (tr_intersect(ray, sh->tr, t, objcolor));
	return (0);
} 