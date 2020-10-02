/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:30:19 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/02 21:27:46 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point		fill_p_1(double a)
{
	t_point p;

	p.x = a;
	p.y = a;
	p.z = a;
	return (p);
}

t_point		fill_p(double a, double b, double c)
{
	t_point p;

	p.x = a;
	p.y = b;
	p.z = c;
	return (p);
}

t_color		fill_clr_3(double a, double b, double c)
{
	t_color p;

	p.r = a;
	p.g = b;
	p.b = c;
	return (p);
}
