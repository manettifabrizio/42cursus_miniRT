/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:18:04 by fmanetti          #+#    #+#             */
/*   Updated: 2020/06/05 13:39:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//trace serve per capire se il raggio colpisce qualche oggetto

int		trace(const t_ray *ray, t_objects sh, float *tnear, t_point *hitobject)
{
	t_uint x; //indice del numero di oggetti
	t_uint objnum = 1; //numero di oggetti (da mettere nella struttura degli oggetti)
	float t; //distanza temporanes

	x = 0;
	*tnear = F_LIMIT;
	while (x < objnum)
	{
		t = F_LIMIT;
		if (intersect(*ray, &sh, &t) && t < *tnear)
		{
			// printf("t = %f\n", t);
			*tnear = t;
			return (1);
		}
		x++;
	}
	return (0);
}