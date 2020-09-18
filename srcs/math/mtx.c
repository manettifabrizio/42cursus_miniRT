/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:23:26 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/16 17:50:42 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

// void	create_trasl_mtx(t_point p, double (*mtx)[4][4])
// {
// 	start_identity_mtx(mtx);
// 	(*mtx)[0][3] = p.x;
// 	(*mtx)[1][3] = p.y;
// 	(*mtx)[2][3] = p.z;
// }

t_matrix	create_rot_mtx(t_point u, double angle, t_matrix mtx)
{
	double s;
	double c;

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

t_point		compute_rot(t_point dir, t_point ax1, t_point ax2)
{
	double		angle;
	t_point 	axis;
	t_matrix 	mtx;

	angle = acos(dot_2(ax1, ax2));
	// printf("angle = %f\n", angle);
	axis = normalize(cross_2(ax2, ax1));
	// print_point(axis, "axis");
	mtx = create_rot_mtx(axis, angle, mtx);
	dir = normalize(mult_vec_mtx(dir, mtx));
	if (angle == M_PI)
		dir.y *= -1;
	// print_point(dir, "dir rot");
	// printf("\n");
	return (dir);
}