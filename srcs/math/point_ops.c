/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:48:28 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/20 20:54:30 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_point		point_sum(t_point p1, t_point p2)
{
	t_point p3;

	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	p3.z = p1.z + p2.z; 
	return (p3);
}

t_point		point_mul(t_point p1, t_point p2)
{
	t_point p2;

	p2.x = p1.x * p2.x;
	p2.y = p1.y * p2.y;
	p2.z = p1.z * p2.z; 
}