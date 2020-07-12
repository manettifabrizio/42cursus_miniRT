/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:06:58 by fmanetti          #+#    #+#             */
/*   Updated: 2020/07/05 21:08:52 by fmanetti         ###   ########.fr       */
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

int		intersect(const t_ray ray, const t_shapes sh, float *t, \
	t_color *hitcolor)
{
	int 		x;

	// printf("x = %d\n", x);
	//printf("tmp.sp.c.z = %f\n", tmp->sp.c.z);
	if (sh.n == 0)
		return (sp_intersect(ray, sh.sp, t, hitcolor));
	else if (sh.n == 1)
		return (pl_intersect(ray, sh.pl, t, hitcolor));
	return (0);
} 