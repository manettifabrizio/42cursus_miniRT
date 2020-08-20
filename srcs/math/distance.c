/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:05:39 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/14 14:35:24 by fmanetti         ###   ########.fr       */
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
{ //da togliere alla fine se non utilizzato
	float 	t;
	t_point p;

	t = (pl.n.x * pl.p.x + pl.n.y * pl.p.y + pl.n.z * pl.p.z) \
		/ (pow(pl.n.x, 2) + pow(pl.n.y, 2) + pow(pl.n.z, 2));
	p.x = pl.n.x * t;
	p.y = pl.n.y * t;
	p.z = pl.n.z * t;
	return (p);
}