/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:18:04 by fmanetti          #+#    #+#             */
/*   Updated: 2020/07/12 08:55:59 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//trace serve per capire se il raggio colpisce qualche oggetto

int		trace(const t_ray *ray, t_objects *obj, float *tnear, t_color *hitcolor)
{
	t_uint		x; //indice del numero di oggetti
	// t_uint objnum = 3; //numero di oggetti (da mettere nella struttura degli oggetti)
	t_shapes	*tmp;
	float 		t; //distanza temporanes

	x = 0;
	*tnear = F_LIMIT;
	tmp = obj->shead;
	while (tmp)
	{
		t = F_LIMIT;
		if (intersect(*ray, *tmp, &t, hitcolor) && t < *tnear)
		{
			printf("t = %f\n", t);
			*tnear = t;
		}
		x++;
		tmp = tmp->next;
	}
	if (t != F_LIMIT)
		return (1);
	return (0);
}