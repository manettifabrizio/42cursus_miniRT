/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:29:54 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/14 12:44:05 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

int		sp_intersect(const t_ray ray, const t_sphere sp, float *t, \
			t_color *objcolor)
{
	float 	t0;
	float	t1;
	t_coeff q;
	// if ((int)ray.dir.x == 0 && (int)ray.dir.y == 0)
		// printf("ray.orig(%f, %f, %f)\nray.dir(%f, %f, %f)\n", ray.orig.x, ray.orig.y, ray.orig.z, ray.dir.x, ray.dir.y, ray.dir.z);
	// printf("c.x = %f\n", sp.c.x);
	// printf("c.y = %f\n", sp.c.y);
	// printf("c.z = %f\n", sp.c.z);
	//METODO scratchapixel
	q.a = dot_1(ray.dir);
	q.b = 2 * dot_2(ray.dir, vec_sub(ray.orig, sp.c));
	q.c = dot_1(vec_sub(ray.orig, sp.c)) - (sp.diam / 2);
	//METODO mio
	// a = dot_1(ray.dir); //D^2
	// b = 2 * dot_2(ray.dir, vec_sub(ray.orig, sp.c)); // -2DC
	// c = dot_1(vec_sub(ray.orig, sp.c)) - pow(sp.diam * 0.5, 2); //O^2 + C^2 - R^2
	// ^ era sbagliato il raggio non era alla 2 controllare
	if (!(quad_solver(q, &t0, &t1)))
		return (0);
	// printf("t0 = %f\nt1 = %f\n", t0, t1);
	if (t0 > t1)
		ft_swap_f(&t0, &t1);
	// if (t1 < 0)
	// {
	// 	t1 = t0;
	// 	if (t0 < 0)
	// 		return (0);
	// }
	*t = t0;
	*objcolor = sp.clr;
	return (1);
}