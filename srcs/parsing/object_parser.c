/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:49:41 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/15 18:50:38 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static void		compute_axis(t_cam *c)
{
	c->n = normalize(c->n);
	c->cz = normalize(mul(c->n, -1));
	c->cx = normalize(cross_2(fill_p(0, 1, 0), c->cz));
	if (isnan(c->cx.x) && isnan(c->cx.z) && isnan(c->cx.y))
		c->cx = (c->cz.y > 0) ? fill_p(1, 0, 0) : fill_p(-1, 0, 0);
	c->cy = normalize(mul(cross_2(c->cx, c->cz), -1));
	print_point(c->n, "tmp->n");
	print_point(c->cx, "cx");
	print_point(c->cy, "cy");
	print_point(c->cz, "cz");
}

int				fill_cam(char *line, t_objects *obj)
{
	t_uint 		x;
	t_cam		*tmp;

	x = 0;
	obj->nc = lst_check_c(&(obj->chead), obj->nc, &tmp); //funziona bene
	if (check(line, 3))
		return (-1);
	tmp->p.x = my_atof(line, &x);
	tmp->p.y = my_atof(line, &x);
	tmp->p.z = my_atof(line, &x);
	tmp->n.x = my_atof(line, &x);
	tmp->n.y = my_atof(line, &x);
	tmp->n.z = my_atof(line, &x);
	tmp->alpha = my_atof(line, &x);
	compute_axis(tmp);
	return (x);
}

int				fill_light(char *line, t_objects *obj)
{
	t_uint 		x;
	t_light		*tmp;

	x = 0;
	obj->nl = lst_check_l(&(obj->lhead), obj->nl, &tmp);
	if (check(line, 3))
		return (-1);
	tmp->p.x = my_atof(line, &x);
	tmp->p.y = my_atof(line, &x);
	tmp->p.z = my_atof(line, &x);
	tmp->rat = my_atof(line, &x);
	tmp->clr.r = my_atoi(line, &x);
	tmp->clr.g = my_atoi(line, &x);
	tmp->clr.b = my_atoi(line, &x);
	return (x);
}
