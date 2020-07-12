/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:05:39 by fmanetti          #+#    #+#             */
/*   Updated: 2020/07/11 18:29:29 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

float		point_dist(t_point p1, t_point p2)
{ 
	return (sqrt(pow((p2.x - p1.x), 2) + \
			pow((p2.y - p1.y), 2) + \
			pow((p2.z - p1.z), 2)));
}

t_point		pointplane_dist(const t_ray ray, const t_plane pl)
{
	float 	t;
	t_point p;

	t = (pl.v.x * pl.p.x + pl.v.y * pl.p.y + pl.v.z * pl.p.z) \
		/ (pow(pl.v.x, 2) + pow(pl.v.y, 2) + pow(pl.v.z, 2));
	p.x = pl.v.x * t;
	p.y = pl.v.y * t;
	p.z = pl.v.z * t;
	return (p);
}