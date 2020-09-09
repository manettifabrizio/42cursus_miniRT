/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:18:04 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/09 23:39:30 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//trace serve per capire se il raggio colpisce qualche oggetto

int		trace(const t_ray *ray, t_objects *obj, double *tnear, t_shapes *hitobj)
{
	// t_uint		x; //indice del numero di oggetti
	// t_uint objnum = 3; //numero di oggetti (da mettere nella struttura degli oggetti)
	t_shapes	*tmp;
	double 		t; //distanza temporanes

	// x = 0;
	*tnear = F_LIMIT;
	tmp = obj->shead;
	// printf("\n");
	while (tmp)
	{
		t = F_LIMIT;
		// printf("tmp->n = %d hitobj->num = %d\n", tmp->num, hitobj->num);
		if (intersect(*ray, tmp, &t) && t < *tnear)
		{
			// printf("tmp->n = %d hitobj->num = %d\n", tmp->num, hitobj->num);
			// printf("x = %d\n", x);
			printf("t = %f\n", t);
			// printf("hit.r = %u, hit.g = %u, hit.b = %u\n", objcolor.r, objcolor.g, objcolor.b);
			*tnear = t;
			*hitobj = *tmp;
		}
		// x++;
		tmp = tmp->next;
	}
	// printf("t3 = %f\n", t);
	if (*tnear != F_LIMIT)
		return (1);
	// printf("ciao\n");
	return (0);
}