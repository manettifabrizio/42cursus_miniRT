/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:49:41 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/26 21:41:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		compute_cam_axis(t_cam *c)
{
	t_point p;

	p = (c->n.y == -1) ? fill_p(0, 0, 1) : fill_p(0, 1, 0);
	c->n = normalize(c->n);
	c->cz = normalize(mul(c->n, -1));
	c->cx = normalize(cross_2(p, c->cz));
	if (isnan(c->cx.x) && isnan(c->cx.z) && isnan(c->cx.y))
		c->cx = (c->cz.y > 0) ? fill_p(1, 0, 0) : fill_p(-1, 0, 0);
	c->cy = normalize(mul(cross_2(c->cx, c->cz), -1));
}

int				fill_cam(char *line, t_uint nln, t_objects *obj)
{
	int		x;
	t_cam	*tmp;

	x = 0;
	obj->nc = lst_check_c(&(obj->chead), obj->nc, &tmp);
	if (check(line, 3))
		return (rt_errors(0, "camera", nln));
	tmp->p.x = my_atof(line, &x);
	tmp->p.y = my_atof(line, &x);
	tmp->p.z = my_atof(line, &x);
	tmp->n.x = my_atof(line, &x);
	tmp->n.y = my_atof(line, &x);
	tmp->n.z = my_atof(line, &x);
	tmp->alpha = my_atof(line, &x);
	compute_cam_axis(tmp);
	check_norm(tmp->n, "camera orientation vector", nln);
	if (tmp->alpha < 0 || tmp->alpha > 180)
		return (rt_errors(1, "camera field of view", nln));
	tmp->scale = tan(deg2rad(tmp->alpha * 0.5));
	return (0);
}

int				fill_light(char *line, t_uint nln, t_objects *obj)
{
	int			x;
	t_light		*tmp;

	x = 0;
	obj->nl = lst_check_l(&(obj->lhead), obj->nl, &tmp);
	if (check(line, 3))
		return (rt_errors(0, "light", nln));
	tmp->p.x = my_atof(line, &x);
	tmp->p.y = my_atof(line, &x);
	tmp->p.z = my_atof(line, &x);
	tmp->rat = my_atof(line, &x);
	if (tmp->rat < 0 || tmp->rat > 1)
		return (rt_errors(1, "light ratio", nln));
	tmp->clr.r = my_atoi(line, &x);
	tmp->clr.g = my_atoi(line, &x);
	tmp->clr.b = my_atoi(line, &x);
	return (check_clr(tmp->clr, "light color", nln));
}
