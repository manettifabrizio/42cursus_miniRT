/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:35:27 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/02 16:59:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		fill_sphere(char *line, t_uint nln, t_objects *obj)
{
	int			x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 3))
		return (rt_errors(0, "sphere", nln));
	tmp->type = 0;
	tmp->sp.c.x = my_atof(line, &x);
	tmp->sp.c.y = my_atof(line, &x);
	tmp->sp.c.z = my_atof(line, &x);
	tmp->sp.diam = my_atof(line, &x);
	tmp->sp.clr.r = my_atoi(line, &x);
	tmp->sp.clr.g = my_atoi(line, &x);
	tmp->sp.clr.b = my_atoi(line, &x);
	return (check_clr(tmp->sp.clr, "sphere color", nln));
}

int		fill_plane(char *line, t_uint nln, t_objects *obj)
{
	int			x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 3))
		return (rt_errors(0, "plane", nln));
	tmp->type = 1;
	tmp->pl.p.x = my_atof(line, &x);
	tmp->pl.p.y = my_atof(line, &x);
	tmp->pl.p.z = my_atof(line, &x);
	tmp->pl.n.x = my_atof(line, &x);
	tmp->pl.n.y = my_atof(line, &x);
	tmp->pl.n.z = my_atof(line, &x);
	tmp->pl.clr.r = my_atoi(line, &x);
	tmp->pl.clr.g = my_atoi(line, &x);
	tmp->pl.clr.b = my_atoi(line, &x);
	x = check_norm(tmp->pl.n, "plane orientation vector", nln);
	tmp->pl.n = normalize(tmp->pl.n);
	x = (x == -1) ? x : check_clr(tmp->pl.clr, "plane color", nln);
	return (x);
}

int		fill_square(char *line, t_uint nln, t_objects *obj)
{
	int			x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 4))
		return (rt_errors(0, "square", nln));
	tmp->type = 2;
	tmp->sq.p.x = my_atof(line, &x);
	tmp->sq.p.y = my_atof(line, &x);
	tmp->sq.p.z = my_atof(line, &x);
	tmp->sq.n.x = my_atof(line, &x);
	tmp->sq.n.y = my_atof(line, &x);
	tmp->sq.n.z = my_atof(line, &x);
	tmp->sq.h = my_atof(line, &x);
	tmp->sq.clr.r = my_atoi(line, &x);
	tmp->sq.clr.g = my_atoi(line, &x);
	tmp->sq.clr.b = my_atoi(line, &x);
	x = check_norm(tmp->sq.n, "square orientation vector", nln);
	tmp->sq.n = normalize(tmp->sq.n);
	x = (x == -1) ? x : check_clr(tmp->sq.clr, "square color", nln);
	return (x);
}

int		fill_cylinder(char *line, t_uint nln, t_objects *obj)
{
	int			x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 5))
		return (rt_errors(0, "cylinder", nln));
	tmp->type = 3;
	tmp->cy.p.x = my_atof(line, &x);
	tmp->cy.p.y = my_atof(line, &x);
	tmp->cy.p.z = my_atof(line, &x);
	tmp->cy.n.x = my_atof(line, &x);
	tmp->cy.n.y = my_atof(line, &x);
	tmp->cy.n.z = my_atof(line, &x);
	tmp->cy.diam = my_atof(line, &x);
	tmp->cy.h = my_atof(line, &x);
	tmp->cy.clr.r = my_atoi(line, &x);
	tmp->cy.clr.g = my_atoi(line, &x);
	tmp->cy.clr.b = my_atoi(line, &x);
	x = check_norm(tmp->cy.n, "cylinder orientation vector", nln);
	tmp->cy.n = normalize(tmp->cy.n);
	x = (x == -1) ? x : check_clr(tmp->cy.clr, "cylinder color", nln);
	return (x);
}

int		fill_triangle(char *line, t_uint nln, t_objects *obj)
{
	int			x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 4))
		return (rt_errors(0, "triangle", nln));
	tmp->type = 4;
	tmp->tr.v0.x = my_atof(line, &x);
	tmp->tr.v0.y = my_atof(line, &x);
	tmp->tr.v0.z = my_atof(line, &x);
	tmp->tr.v1.x = my_atof(line, &x);
	tmp->tr.v1.y = my_atof(line, &x);
	tmp->tr.v1.z = my_atof(line, &x);
	tmp->tr.v2.x = my_atof(line, &x);
	tmp->tr.v2.y = my_atof(line, &x);
	tmp->tr.v2.z = my_atof(line, &x);
	tmp->tr.clr.r = my_atoi(line, &x);
	tmp->tr.clr.g = my_atoi(line, &x);
	tmp->tr.clr.b = my_atoi(line, &x);
	tmp->tr.n = normalize(cross_2(sub(tmp->tr.v1, tmp->tr.v0), \
		sub(tmp->tr.v2, tmp->tr.v0)));
	return (check_clr(tmp->tr.clr, "triangle color", nln));
}
