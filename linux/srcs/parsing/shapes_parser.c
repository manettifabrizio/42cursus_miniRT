/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:35:27 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/10 09:48:56 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		fill_sphere(char *line, t_parse p, t_objects *obj)
{
	int			x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 3))
		return (rt_errors(1, "sphere", p.nln));
	tmp->type = 0;
	tmp->sp.c.x = my_atof(line, &x, p, "sphere center");
	tmp->sp.c.y = my_atof(line, &x, p, "sphere center");
	tmp->sp.c.z = my_atof(line, &x, p, "sphere center");
	tmp->sp.diam = my_atof(line, &x, p, "sphere diameter");
	if (tmp->sp.diam < 0)
		return (rt_errors(2, "sphere diameter", p.nln));
	tmp->sp.clr.r = my_atoi(line, &x, p, "sphere color");
	tmp->sp.clr.g = my_atoi(line, &x, p, "sphere color");
	tmp->sp.clr.b = my_atoi(line, &x, p, "sphere color");
	return (check_clr(tmp->sp.clr, "sphere color", p.nln));
}

int		fill_plane(char *line, t_parse p, t_objects *obj)
{
	int			x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 3))
		return (rt_errors(1, "plane", p.nln));
	tmp->type = 1;
	tmp->pl.p.x = my_atof(line, &x, p, "plane point");
	tmp->pl.p.y = my_atof(line, &x, p, "plane point");
	tmp->pl.p.z = my_atof(line, &x, p, "plane point");
	tmp->pl.n.x = my_atof(line, &x, p, "plane orientation vector");
	tmp->pl.n.y = my_atof(line, &x, p, "plane orientation vector");
	tmp->pl.n.z = my_atof(line, &x, p, "plane orientation vector");
	tmp->pl.clr.r = my_atoi(line, &x, p, "plane color");
	tmp->pl.clr.g = my_atoi(line, &x, p, "plane color");
	tmp->pl.clr.b = my_atoi(line, &x, p, "plane color");
	x = check_norm(tmp->pl.n, "plane orientation vector", p.nln);
	tmp->pl.n = normalize(tmp->pl.n);
	x = (x == -1) ? x : check_clr(tmp->pl.clr, "plane color", p.nln);
	return (x);
}

int		fill_square(char *line, t_parse p, t_objects *obj)
{
	int			x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 4))
		return (rt_errors(1, "square", p.nln));
	tmp->type = 2;
	tmp->sq.p.x = my_atof(line, &x, p, "square center");
	tmp->sq.p.y = my_atof(line, &x, p, "square center");
	tmp->sq.p.z = my_atof(line, &x, p, "square center");
	tmp->sq.n.x = my_atof(line, &x, p, "square orientation vector");
	tmp->sq.n.y = my_atof(line, &x, p, "square orientation vector");
	tmp->sq.n.z = my_atof(line, &x, p, "square orientation vector");
	tmp->sq.h = my_atof(line, &x, p, "square heigth");
	if (tmp->sq.h < 0)
		return (rt_errors(2, "square heigth", p.nln));
	tmp->sq.clr.r = my_atoi(line, &x, p, "square color");
	tmp->sq.clr.g = my_atoi(line, &x, p, "square color");
	tmp->sq.clr.b = my_atoi(line, &x, p, "square color");
	x = check_norm(tmp->sq.n, "square orientation vector", p.nln);
	tmp->sq.n = normalize(tmp->sq.n);
	x = (x == -1) ? x : check_clr(tmp->sq.clr, "square color", p.nln);
	return (x);
}

int		fill_cylinder(char *line, t_parse p, t_objects *obj)
{
	int			x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 5))
		return (rt_errors(1, "cylinder", p.nln));
	tmp->type = 3;
	tmp->cy.p.x = my_atof(line, &x, p, "cylinder center");
	tmp->cy.p.y = my_atof(line, &x, p, "cylinder center");
	tmp->cy.p.z = my_atof(line, &x, p, "cylinder center");
	tmp->cy.n.x = my_atof(line, &x, p, "cylinder orientation vector");
	tmp->cy.n.y = my_atof(line, &x, p, "cylinder orientation vector");
	tmp->cy.n.z = my_atof(line, &x, p, "cylinder orientation vector");
	tmp->cy.diam = my_atof(line, &x, p, "cylinder diameter");
	tmp->cy.h = my_atof(line, &x, p, "cylinder heigth");
	if (check_cylinder(tmp->cy, p) == -1)
		return (-1);
	tmp->cy.clr.r = my_atoi(line, &x, p, "cylinder color");
	tmp->cy.clr.g = my_atoi(line, &x, p, "cylinder color");
	tmp->cy.clr.b = my_atoi(line, &x, p, "cylinder color");
	x = check_norm(tmp->cy.n, "cylinder orientation vector", p.nln);
	tmp->cy.n = normalize(tmp->cy.n);
	x = (x == -1) ? x : check_clr(tmp->cy.clr, "cylinder color", p.nln);
	return (x);
}

int		fill_triangle(char *line, t_parse p, t_objects *obj)
{
	int			x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 4))
		return (rt_errors(1, "triangle", p.nln));
	tmp->type = 4;
	tmp->tr.v0.x = my_atof(line, &x, p, "triangle vertex 1");
	tmp->tr.v0.y = my_atof(line, &x, p, "triangle vertex 1");
	tmp->tr.v0.z = my_atof(line, &x, p, "triangle vertex 1");
	tmp->tr.v1.x = my_atof(line, &x, p, "triangle vertex 2");
	tmp->tr.v1.y = my_atof(line, &x, p, "triangle vertex 2");
	tmp->tr.v1.z = my_atof(line, &x, p, "triangle vertex 2");
	tmp->tr.v2.x = my_atof(line, &x, p, "triangle vertex 3");
	tmp->tr.v2.y = my_atof(line, &x, p, "triangle vertex 3");
	tmp->tr.v2.z = my_atof(line, &x, p, "triangle vertex 3");
	tmp->tr.clr.r = my_atoi(line, &x, p, "triangle color");
	tmp->tr.clr.g = my_atoi(line, &x, p, "triangle color");
	tmp->tr.clr.b = my_atoi(line, &x, p, "triangle color");
	tmp->tr.n = normalize(cross_2(sub(tmp->tr.v1, tmp->tr.v0), \
		sub(tmp->tr.v2, tmp->tr.v0)));
	return (check_clr(tmp->tr.clr, "triangle color", p.nln));
}
