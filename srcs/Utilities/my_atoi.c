/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 11:15:09 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 17:43:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int		spaces_and_sign(const char *s, int *x, int *c)
{
	if (s[*x] == '\0')
		return (1);
	while (s[*x] == ' ' || (s[*x] >= 8 && s[*x] <= 13))
		(*x)++;
	if (s[*x] == '-')
		return (1);
	while (s[(*x) + (*c)] == '+' || s[(*x) + (*c)] == '-')
		(*c)++;
	if ((*c) > 1)
		return (1);
	return (0);
}

int		my_atoi(const char *s, int *x)
{
	int c;
	int res;

	c = 0;
	res = 0;
	if (spaces_and_sign(s, x, &c))
		return (-1);
	while (s[(*x) + c] >= '0' && s[(*x) + c] <= '9')
	{
		res *= 10;
		res += (int)s[(*x) + c] - '0';
		(*x)++;
	}
	(*x) += c;
	if (s[*x] == ',')
		(*x)++;
	return (res);
}
