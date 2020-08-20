/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 21:24:39 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/08 20:35:52 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int		quad_solver(const t_coeff d, float *x0, float *x1)
{
	float q;
	float delta;

	// printf("a = %f\nb = %f\nc = %f\n", a, b, c);
	delta = pow(d.b, 2) - (4 * d.a * d.c);
	if (delta < 0)
		return (0);
	else if (delta == 0)
		*x0 = *x1 = -0.5 * d.b / d.a;
	else
	{
		if (d.b > 0)
			q = -0.5 * (d.b + sqrt(delta));
		else 
			q = -0.5 * (d.b - sqrt(delta));
		*x0 = q / d.a;
		*x1 = d.c / q;  
	}
	if (*x0 > *x1)
		ft_swap_f(x0, x1);
	return (1);
}