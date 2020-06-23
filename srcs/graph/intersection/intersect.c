/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:06:58 by fmanetti          #+#    #+#             */
/*   Updated: 2020/06/15 14:59:56 by fmanetti         ###   ########.fr       */
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

int		intersect(const t_ray ray, const t_objects *sh, float *t)
{
	int x;

	x = sh->ns;
	while (x--)
	{
		// print_sp(*sh);
		//sp_intersect(ray, *sh.sp, t);
		// sh = (sh->next);
	}
	return (1);
}