/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:21:53 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/06 16:48:57 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		clr_mul(t_color clr0, double t)
{
	t_color clr;

	clr.r = clr0.r * t;
	clr.g = clr0.g * t;
	clr.b = clr0.b * t;
	return (clr);
}

t_color		clr_d_mul(t_color clr, double x)
{
	t_color clr1;

	clr1.r = clr.r * x;
	clr1.g = clr.g * x;
	clr1.b = clr.b * x;
	return (clr1);
}

t_color		mix_clr(t_color light, t_color shape, double ratio)
{
	t_color clr;

	clr.r = ratio * light.r / 255 * shape.r;
	clr.g = ratio * light.g / 255 * shape.g;
	clr.b = ratio * light.b / 255 * shape.b;
	return (clr);
}

t_color		max_clr(t_color clr, t_color objclr)
{
	if (clr.r > objclr.r)
		clr.r = objclr.r;
	if (clr.g > objclr.g)
		clr.g = objclr.g;
	if (clr.b > objclr.b)
		clr.b = objclr.b;
	return (clr);
}
