/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:51:25 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/23 08:55:16 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_point	normalize(t_point p)
{
	float factor;

	factor = sqrt(pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2));
	p.x /= factor;
	p.y /= factor;
	p.z /= factor;
	return (p);
}