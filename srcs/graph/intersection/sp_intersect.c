/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:29:54 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/25 11:35:17 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

int		sp_intersect(const t_ray ray, t_shapes *sh, float *t)
{
	float 	t0;
	float	t1;
	t_coeff q;
	t_point phit;

	q.a = dot_1(ray.dir);
	q.b = 2 * dot_2(ray.dir, vec_sub(ray.orig, sh->sp.c));
	q.c = dot_1(vec_sub(ray.orig, sh->sp.c)) - (sh->sp.diam / 2);
	if (!(quad_solver(q, &t0, &t1)))
		return (0);
	if (t0 > t1)
		ft_swap_f(&t0, &t1);
	*t = t0;
	phit = vec_sum(ray.orig, point_mul(ray.dir, fill_point_1(*t)));
	sh->nhit = normalize(vec_sub(phit, sh->sp.c));
	sh->objclr = sh->sp.clr;
	return (1);
}