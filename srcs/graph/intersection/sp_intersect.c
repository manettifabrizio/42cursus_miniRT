/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:29:54 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/26 10:11:55 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

int		sp_intersect(const t_ray ray, const t_sphere sp, float *t)
{
	float	a;
	float 	b;
	float	c;
	float	dist;
	float t0 = 0.0, t1 = 0.0;

	a = dot_product_1(ray.dir); //D^2
	b = - 2 * dot_product_2(ray.dir, sp.c); // -2DC
	c = dot_product_1(ray.orig) + dot_product_1(sp.c) - pow(sp.d * 0.5, 2); //O^2 + C^2 - R^2
	// ^ era sbagliato il raggio non era alla 2 controllare
	if (!(quad_solver(a, b, c, &t0, &t1)))
		return (0);
	if (t0 > t1)
		ft_swap_f(&t0, &t1);
	if (t1 < 0)
	{
		t1 = t0;
		if (t0 < 0)
			return (0);
	}
	*t = t0;
	return (1);
}