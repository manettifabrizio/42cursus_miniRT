/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:29:54 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/01 12:30:55 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

int		sp_intersect(const t_ray ray, const t_sphere sp, float *t, t_color *hitcolor)
{
	float	a;
	float 	b;
	float	c;
	float	dist;
	float t0 = 0.0, t1 = 0.0;

	if ((int)ray.dir.x == 0 && (int)ray.dir.y == 0)
		printf("ray.orig(%f, %f, %f)\nray.dir(%f, %f, %f)\n", ray.orig.x, ray.orig.y, ray.orig.z, ray.dir.x, ray.dir.y, ray.dir.z);
	// printf("c.x = %f\n", sp.c.x);
	// printf("c.y = %f\n", sp.c.y);
	// printf("c.z = %f\n", sp.c.z);
	t_point L;
	L = vector_sub(ray.orig, sp.c);
	a = dot_product_1(ray.dir);
	b = 2 * dot_product_2(ray.dir, L);
	c = dot_product_1(L) - (sp.d / (float)2);
	// a = dot_product_1(ray.dir); //D^2
	// b = 2 * dot_product_2(ray.dir, vector_sub(ray.orig, sp.c)); // -2DC
	// c = dot_product_1(vector_sub(ray.orig, sp.c)) - pow(sp.d * 0.5, 2); //O^2 + C^2 - R^2
	// ^ era sbagliato il raggio non era alla 2 controllare
	if (!(quad_solver(a, b, c, &t0, &t1)))
		return (0);
	printf("t0 = %f\nt1 = %f\n", t0, t1);
	if (t0 > t1)
		ft_swap_f(&t0, &t1);
	if (t1 < 0)
	{
		t1 = t0;
		if (t0 < 0)
			return (0);
	}
	*t = t0;
	*hitcolor = fill_clr_3(sp.clr.r, sp.clr.g, sp.clr.b);
	return (1);
}