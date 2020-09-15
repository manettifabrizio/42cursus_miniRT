/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:42:26 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/10 18:00:43 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

// void		mult_pt_mtx(t_point src, t_matrix m, t_point dst)
// {
// 	double a;
// 	double b;
// 	double c;
// 	double w;

// 	a = src.x * m.a.x + src.y * m[1][0] + src.z *	m[2][0] \
// 		+ m[3][0];
// 	b = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1] \
// 		+ m[3][1];
//     c = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2] \
// 		+ m[3][2];
//     w = src.x * m[0][3] + src.y * m[1][3] + src.z * m[2][3] \
// 		+ m[3][3];

// 	dst.x = a / w;
//     dst.y = b / w; //perché divido per w non lo so
//     dst.z = c / w;
// }

t_point		mult_vec_mtx(t_point p, t_matrix m)
{
	t_point p1;

	p1.x = dot_2(p, m.a);
    p1.y = dot_2(p, m.b);
    p1.z = dot_2(p, m.c);
    return (p1);
}