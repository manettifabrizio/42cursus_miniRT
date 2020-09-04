/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:29:54 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/02 15:23:40 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

int		sp_intersect(const t_ray ray, t_shapes *sh, double *t)
{
	double 	t0;
	double	t1;
	t_coeff q;

	q.a = dot_1(ray.dir);
	q.b = 2 * dot_2(ray.dir, vec_sub(ray.orig, sh->sp.c));
	q.c = dot_1(vec_sub(ray.orig, sh->sp.c)) - (sh->sp.diam / 2);
	if (!(quad_solver(q, &t0, &t1)))
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
	sh->objclr = sh->sp.clr;
	return (1);
	//controllare se funziona
}