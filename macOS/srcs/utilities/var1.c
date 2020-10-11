/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 23:52:08 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/10 09:54:31 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_cylinder(t_cylinder cy, t_parse p)
{
	if (cy.diam < 0)
		return (rt_errors(2, "cylinder diameter", p.nln));
	else if (cy.h < 0)
		return (rt_errors(2, "cylinder heigth", p.nln));
	return (0);
}
