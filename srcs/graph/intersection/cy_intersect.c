/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:22:17 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/14 17:52:36 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

static int		check_cy(const t_ray ray, const t_cylinder cy, float t0, \
					float t1)
{
	float m0;
	float m1;

	m0 = (dot_2(ray.dir, cy.n) * t0) + \
		dot_2(vec_sub(ray.orig, cy.p), cy.n);
	m1 = (dot_2(ray.dir, cy.n) * t1) + \
		dot_2(vec_sub(ray.orig, cy.p), cy.n);
	// printf("m0 = %f m1 = %f\n", m0, m1);
	m0 = (m0 > -(cy.h / 2) && m0 < cy.h / 2) ? 1 : 0;
	m1 = (m1 > -(cy.h / 2) && m1 < cy.h / 2) ? 1 : 0;
	if (m0 && m1)
		return ((t0 > t1) ? t1 : t0);
	else if (m0 && !(m1))
		return (t0);
	else if (!(m0) && m1)
		return (t1);
	return (0);
}

int				cy_intersect(const t_ray ray, const t_cylinder cy, float *t, \
					t_color *objcolor)
{
	float	t0;
	float	t1;
	t_coeff	q;
	t_point	x;

	// print_point(cy.n, "cy.n");
	x = vec_sub(ray.orig, cy.p);
	q.a = dot_1(ray.dir) - pow(dot_2(ray.dir, cy.n), 2);
	q.b = 2 * (dot_2(ray.dir, x) - (dot_2(ray.dir, cy.n) * \
		dot_2(x, cy.n)));
	q.c = dot_1(x) - pow(dot_2(x, cy.n), 2) - \
		pow(cy.diam / 2, 2);
	if (!(quad_solver(q, &t0, &t1)))
		return (0);
	*t = check_cy(ray, cy, t0, t1);
	// printf ("t = %f\n", *t);
	if (*t <= 0)
		return (0); // da ricontrollare per i valori di t negativi
	*objcolor = cy.clr;
	return (1);
}