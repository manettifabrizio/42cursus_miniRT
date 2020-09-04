/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:35:27 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/01 17:41:38 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int		fill_sphere(char *line, t_objects *obj)
{
	t_uint 		x;
	t_shapes	*tmp;
	
	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	// printf("tmp = %p\n", tmp);
	// printf("shead = %p\n", obj->shead);
	if (check(line, 3))
		return (-1);
	tmp->type = 0;
	tmp->sp.c.x = my_atof(line, &x);
	// printf("a c.x = %f\n", tmp->sp.c.x);
	tmp->sp.c.y = my_atof(line, &x);
	tmp->sp.c.z = my_atof(line, &x);
	tmp->sp.diam = my_atof(line, &x);
	tmp->sp.clr.r = my_atoi(line, &x);
	tmp->sp.clr.g = my_atoi(line, &x);
	tmp->sp.clr.b = my_atoi(line, &x);
	//printf("hit.r = %u, hit.g = %u, hit.b = %u\n", tmp->sp.clr.r, tmp->sp.clr.g, tmp->sp.clr.b);
	return (x);
}

int		fill_plane(char *line, t_objects *obj)
{
	t_uint		x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 3))
		return (-1);
	tmp->type = 1;
	tmp->pl.p.x = my_atof(line, &x);
	tmp->pl.p.y = my_atof(line, &x);
	tmp->pl.p.z = my_atof(line, &x);
	tmp->pl.n.x = my_atof(line, &x);
	tmp->pl.n.y = my_atof(line, &x);
	tmp->pl.n.z = my_atof(line, &x);
	// printf("line[%u] = %c\n", x, line[x]);
	tmp->pl.clr.r = my_atoi(line, &x);
	tmp->pl.clr.g = my_atoi(line, &x);
	tmp->pl.clr.b = my_atoi(line, &x);
	tmp->pl.n = normalize(tmp->pl.n);
	// printf("hit.r = %u, hit.g = %u, hit.b = %u\n", tmp->pl.clr.r, tmp->pl.clr.g, tmp->pl.clr.b);
	return (x);
}

int		fill_square(char *line, t_objects *obj)
{
	t_uint		x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 4))
		return (-1);
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
	tmp->sq.n = normalize(tmp->sq.n);
	return (x);
}

int		fill_cylinder(char *line, t_objects *obj)
{
	t_uint		x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 5))
		return (-1);
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
	tmp->cy.n = normalize(tmp->cy.n);
	return (x);
}

int		fill_triangle(char *line, t_objects *obj)
{
	t_uint		x;
	t_shapes	*tmp;

	x = 0;
	obj->ns = lst_check_s(&(obj->shead), obj->ns, &tmp);
	if (check(line, 4))
		return (-1);
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
	tmp->tr.n = cross_2(vec_sub(tmp->tr.v1, tmp->tr.v0), \
		vec_sub(tmp->tr.v2, tmp->tr.v0));
	tmp->tr.dist = dot_2(tmp->tr.n, tmp->tr.v0);
	return (x);
}