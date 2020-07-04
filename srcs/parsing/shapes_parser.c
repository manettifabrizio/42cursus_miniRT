/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:35:27 by fmanetti          #+#    #+#             */
/*   Updated: 2020/06/23 10:16:41 by fmanetti         ###   ########.fr       */
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
	tmp->n = 0;
	tmp->sp.c.x = my_atof(line, &x);
	// printf("a c.x = %f\n", tmp->sp.c.x);
	tmp->sp.c.y = my_atof(line, &x);
	tmp->sp.c.z = my_atof(line, &x);
	tmp->sp.d = my_atof(line, &x);
	tmp->sp.clr.r = my_atof(line, &x);
	tmp->sp.clr.g = my_atof(line, &x);
	tmp->sp.clr.b = my_atof(line, &x);
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
	tmp->n = 1;
	tmp->pl.p.x = my_atof(line, &x);
	tmp->pl.p.y = my_atof(line, &x);
	tmp->pl.p.z = my_atof(line, &x);
	tmp->pl.v.x = my_atof(line, &x);
	tmp->pl.v.y = my_atof(line, &x);
	tmp->pl.v.z = my_atof(line, &x);
	tmp->pl.clr.r = my_atof(line, &x);
	tmp->pl.clr.g = my_atof(line, &x);
	tmp->pl.clr.b = my_atof(line, &x);
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
	tmp->n = 2;
	tmp->sq.p.x = my_atof(line, &x);
	tmp->sq.p.y = my_atof(line, &x);
	tmp->sq.p.z = my_atof(line, &x);
	tmp->sq.v.x = my_atof(line, &x);
	tmp->sq.v.y = my_atof(line, &x);
	tmp->sq.v.z = my_atof(line, &x);
	tmp->sq.h = my_atof(line, &x);
	tmp->sq.clr.r = my_atof(line, &x);
	tmp->sq.clr.g = my_atof(line, &x);
	tmp->sq.clr.b = my_atof(line, &x);
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
	tmp->n = 3;
	tmp->cy.p.x = my_atof(line, &x);
	tmp->cy.p.y = my_atof(line, &x);
	tmp->cy.p.z = my_atof(line, &x);
	tmp->cy.v.x = my_atof(line, &x);
	tmp->cy.v.y = my_atof(line, &x);
	tmp->cy.v.z = my_atof(line, &x);
	tmp->cy.d = my_atof(line, &x);
	tmp->cy.h = my_atof(line, &x);
	tmp->cy.clr.r = my_atof(line, &x);
	tmp->cy.clr.g = my_atof(line, &x);
	tmp->cy.clr.b = my_atof(line, &x);
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
	tmp->n = 4;
	tmp->tr.p1.x = my_atof(line, &x);
	tmp->tr.p1.y = my_atof(line, &x);
	tmp->tr.p1.z = my_atof(line, &x);
	tmp->tr.p2.x = my_atof(line, &x);
	tmp->tr.p2.y = my_atof(line, &x);
	tmp->tr.p2.z = my_atof(line, &x);
	tmp->tr.p3.x = my_atof(line, &x);
	tmp->tr.p3.y = my_atof(line, &x);
	tmp->tr.p3.z = my_atof(line, &x);
	tmp->tr.clr.r = my_atof(line, &x);
	tmp->tr.clr.g = my_atof(line, &x);
	tmp->tr.clr.b = my_atof(line, &x);
	return (x);
}