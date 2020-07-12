/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 11:15:09 by fmanetti          #+#    #+#             */
/*   Updated: 2020/07/12 07:50:36 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int		my_atoi(const char *s, t_uint *x)
{
	int c;
	int res;
	int sign;

	c = 0;
	res = 0;
	sign = 1;
	while (s[*x] == ' ' || (s[*x] >= 8 && s[*x] <= 13))
		(*x)++;
	sign *= (s[*x] == '-') ? -1 : 1;
	while (s[(*x) + c] == '+' || s[(*x) + c] == '-')
		c++;
	while (s[(*x) + c] >= '0' && s[(*x) + c] <= '9')
	{
		res *= 10;
		res += (int)s[(*x) + c] - '0';
		(*x)++;
	}
	if (c > 1)
		return (0);
	(*x) += c;
	if (s[*x] == ',')
		(*x)++;
	return (res * sign);
}
