/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 10:48:01 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/02 21:28:33 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		pl_intersect(const t_ray ray, t_shapes *sh, double *t)
{
	*t = dot_2(sub(sh->pl.p, ray.orig), sh->pl.n) /
		dot_2(sh->pl.n, ray.dir);
	if (*t > 0)
	{
		sh->objclr = sh->pl.clr;
		return (1);
	}
	return (0);
}
