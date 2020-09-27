/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:23:26 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 20:03:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static	t_matrix	create_rot_mtx(t_point u, double angle)
{
	double		s;
	double		c;
	t_matrix	mtx;

	s = sin(angle);
	c = cos(angle);
	mtx.a = fill_p(c + pow(u.x, 2) * (1 - c),
					u.x * u.y * (1 - c) - u.z * s,
					u.x * u.z * (1 - c) + u.y * s);
	mtx.b = fill_p(u.y * u.x * (1 - c) + u.z * s,
					c + pow(u.y, 2) * (1 - c),
					u.y * u.z * (1 - c) - u.x * s);
	mtx.c = fill_p(u.z * u.x * (1 - c) - u.y * s,
					u.z * u.y * (1 - c) + u.x * s,
					c + pow(u.z, 2) * (1 - c));
	return (mtx);
}

t_matrix			compute_rot(t_point ax1, t_point ax2, t_setting *set)
{
	double		angle;
	t_point		axis;
	t_matrix	mtx;

	angle = acos(dot_2(ax1, ax2));
	axis = normalize(cross_2(ax2, ax1));
	mtx = create_rot_mtx(axis, angle);
	if (angle == M_PI && ax2.x == 1)
		set->inversex = -1;
	if (angle == M_PI && ax2.y == 1)
		set->inversey = -1;
	return (mtx);
}

t_point				mult_vec_mtx(t_point p, t_matrix m)
{
	t_point p1;

	p1.x = dot_2(p, m.a);
	p1.y = dot_2(p, m.b);
	p1.z = dot_2(p, m.c);
	return (p1);
}
