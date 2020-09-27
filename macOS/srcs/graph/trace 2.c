/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:18:04 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/26 21:41:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		trace(const t_ray *ray, t_objects *obj, double *tnear, t_shapes *hitobj)
{
	t_shapes	*tmp;
	double		t;

	*tnear = F_LIMIT;
	tmp = obj->shead;
	while (tmp)
	{
		t = F_LIMIT;
		if (intersect(*ray, tmp, &t) && t < *tnear)
		{
			*tnear = t;
			*hitobj = *tmp;
		}
		tmp = tmp->next;
	}
	if (*tnear != F_LIMIT)
		return (1);
	return (0);
}
