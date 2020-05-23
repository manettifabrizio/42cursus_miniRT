/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:42:26 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/23 08:45:57 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void		mult_pt_mtx(t_point src, float m[4][4], t_point dst)
{
	float a;
	float b;
	float c;
	float w;

	a = src.x * m[0][0] + src.y * m[1][0] + src.z *	m[2][0] \
		+ m[3][0];
	b = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1] \
		+ m[3][1];
    c = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2] \
		+ m[3][2];
    w = src.x * m[0][3] + src.y * m[1][3] + src.z * m[2][3] \
		+ m[3][3];

	dst.x = a / w;
    dst.y = b / w; //perché divido per w non lo so
    dst.z = c / w;
}

void		mult_vec_mtx(t_point src, float m[4][4], t_point dst)
{
	float a;
	float b;
	float c;

	a = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0];
    b = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1];
    c = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2];
        
    dst.x = a;
    dst.y = b;
    dst.z = c;
}