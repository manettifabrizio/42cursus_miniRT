/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:06:58 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/26 21:41:33 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		intersect(const t_ray ray, t_shapes *sh, double *t)
{
	if (sh->type == 0)
		return (sp_intersect(ray, sh, t));
	else if (sh->type == 1)
		return (pl_intersect(ray, sh, t));
	else if (sh->type == 2)
		return (sq_intersect(ray, sh, t));
	else if (sh->type == 3)
		return (cy_intersect(ray, sh, t));
	else if (sh->type == 4)
		return (tr_intersect(ray, sh, t));
	return (0);
}
