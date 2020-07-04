/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:30:19 by fmanetti          #+#    #+#             */
/*   Updated: 2020/07/03 10:42:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_point		fill_point_1(float a)
{
	t_point p;
	
	p.x = a;
	p.y = a;
	p.z = a;
	return (p);
}

t_point		fill_point_2(float a)
{
	t_point p;

	p.x = a;
	p.y = a;
	p.z = a;
	return (p);
}

t_point		fill_point_3(float a, float b, float c)
{
	t_point p;

	p.x = a;
	p.y = b;
	p.z = c;
	return (p);
}

t_color		fill_clr_3(float a, float b, float c)
{
	t_color p;

	p.r = a;
	p.g = b;
	p.b = c;
	return (p);
}