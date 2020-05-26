/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:27:20 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/24 17:31:30 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_swap_f(float *a, float *b)
{
	float tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}