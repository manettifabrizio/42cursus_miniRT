/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 12:07:24 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 20:03:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		parse_sign(const char *s, int *i)
{
	int			sign;
	t_uint		x;

	x = 0;
	sign = 1;
	if (s[*i] == '-')
		sign = -1;
	while (s[*i] == '+' || s[*i] == '-')
	{
		x++;
		(*i)++;
	}
	if (x > 1)
		return (0);
	return (sign);
}

static double	parse_digits(const char *s, t_uint *count, int *i)
{
	double	x;

	x = 0;
	(*count) = 0;
	while (ft_isdigit(s[*i]))
	{
		x = x * 10.0 + (s[*i] - '0');
		(*count)++;
		(*i)++;
	}
	return (x);
}

double			my_atof(const char *s, int *i)
{
	double		x;
	double		dec;
	int			sign;
	t_uint		c;

	c = 0;
	dec = 0.0;
	while (s[*i] == ' ' || (s[*i] >= 8 && s[*i] <= 13))
		(*i)++;
	if ((sign = parse_sign(s, i)) == 0)
		return (0.0);
	x = parse_digits(s, &c, i);
	if (s[*i] == '.')
	{
		(*i)++;
		dec = parse_digits(s, &c, i);
	}
	while (c--)
		dec /= 10;
	x += dec;
	if (sign < 0)
		x *= -1;
	if (s[*i] == ',')
		(*i)++;
	return (x);
}
