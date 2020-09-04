/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:06:58 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/02 13:22:20 by fmanetti         ###   ########.fr       */
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

int		intersect(const t_ray ray, t_shapes *sh, double *t)
{
	if (sh->type == 0)
		return (sp_intersect(ray, sh, t));
	else if (sh->type == 1)
		return (pl_intersect(ray, sh, t));
	else if (sh->type == 2)
	 	return (sq_intersect(ray, sh, t));
	// else if (sh->type == 3)
	//  	return (cy_intersect(ray, sh, t));
	// else if (sh->type == 4)
	// 	return (tr_intersect(ray, sh, t));
	return (0);
} 