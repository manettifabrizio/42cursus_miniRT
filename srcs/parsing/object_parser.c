/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:49:41 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/14 14:35:47 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int				fill_cam(char *line, t_objects *obj)
{
	t_uint 		x;
	t_cam		*tmp;

	x = 0;
	obj->nc = lst_check_c(&(obj->chead), obj->nc, &tmp); //funziona bene
	if (check(line, 3))
		return (-1);
	// printf("1\n");
	// printf("line = %s\n", line);
	tmp->c.x = my_atof(line, &x);
	// printf("tmp->c.x = %f\n", tmp->c.x);
	// // printf("x = %u\n", x);
	// // printf("2\n");
	tmp->c.y = my_atof(line, &x);
	// printf("tmp->c.y = %f\n", tmp->c.y);
	// // printf("3\n");
	tmp->c.z = my_atof(line, &x);
	// printf("tmp->c.z = %f\n", tmp->c.z);
	// // printf("\n");
	tmp->n.x = my_atof(line, &x);
	// // printf("4\n");
	tmp->n.y = my_atof(line, &x);
	// // printf("5\n");
	tmp->n.z = my_atof(line, &x);
	// //print_point(tmp->n);
	// // printf("\n");
	tmp->alpha = my_atof(line, &x);
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
	tmp->c.x = my_atof(line, &x);
	tmp->c.y = my_atof(line, &x);
	tmp->c.z = my_atof(line, &x);
	tmp->rat = my_atof(line, &x);
	tmp->clr.r = my_atoi(line, &x);
	tmp->clr.g = my_atoi(line, &x);
	tmp->clr.b = my_atoi(line, &x);
	return (x);
}
