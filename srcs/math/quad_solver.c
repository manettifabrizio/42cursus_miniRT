/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 21:24:39 by fmanetti          #+#    #+#             */
/*   Updated: 2020/07/05 20:57:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int		quad_solver(const float a, const float b, const float c, float *x0, float *x1)
{
	float delta;
	float q;

	// printf("a = %f\nb = %f\nc = %f\n", a, b, c);
	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0)
		return (0);
	else if (delta == 0)
		*x0 = *x1 = -0.5 * b / a;
	else
	{
		if (b > 0)
			q = -0.5 * (b + sqrt(delta));
		else 
			q = -0.5 * (b - sqrt(delta));
		*x0 = q / a;
		*x1 = c / q;  
	}
	if (*x0 > *x1)
		ft_swap_f(x0, x1);
	return (1);
}