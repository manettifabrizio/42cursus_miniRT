/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:18:04 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/20 09:55:11 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//trace serve per capire se il raggio colpisce qualche oggetto

int		trace(const t_ray *ray, t_objects *obj, float *tnear, t_color *hitcolor)
{
	t_uint		x; //indice del numero di oggetti
	// t_uint objnum = 3; //numero di oggetti (da mettere nella struttura degli oggetti)
	t_shapes	*tmp;
	t_color		objcolor;
	float 		t; //distanza temporanes

	x = 0;
	*tnear = F_LIMIT;
	tmp = obj->shead;
	while (tmp)
	{
		t = F_LIMIT;
		if (intersect(*ray, *tmp, &t, &objcolor) && t < *tnear)
		{
			// printf("t = %f\n", t);
			// printf("hit.r = %u, hit.g = %u, hit.b = %u\n", objcolor.r, objcolor.g, objcolor.b);
			*tnear = t; //il t per ora è inutilizzato
			*hitcolor = objcolor;
		}
		x++;
		tmp = tmp->next;
	}
	if (t != F_LIMIT)
		return (1);
	return (0);
}