/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:51:25 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 20:03:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double	norm(t_point p)
{
	return (p.x * p.x + p.y * p.y + p.z * p.z);
}

t_point	normalize(t_point p)
{
	double factor;

	factor = sqrt(norm(p));
	if (factor > 0)
	{
		p.x /= factor;
		p.y /= factor;
		p.z /= factor;
	}
	return (p);
}
