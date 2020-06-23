/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 10:38:15 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/28 18:57:01 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		parse_sign(const char **const s)
{
	int 			sign;
	unsigned int 	x;

	x = 0;
	sign = 1;
	if (**s == '-')
		sign = -1;
	while (**s == '+' || **s == '-')
	{
		x++;
		(*s)++;
	}
	if (x > 1)
		return (0);
	return (sign);
}

static double	parse_digits(const char **const s, unsigned int *count)
{
	double	x;

	x = 0;
	(*count) = 0;
	while (ft_isdigit(**s))
	{
		x = x * 10.0 + (*(*s)++ - '0');
		(*count)++;
	}
	return (x);
}

float			ft_atof(const char *s)
{
	float 			x;
	float 			dec;
	int				sign;
	unsigned int	c;
	
	c = 0;
	while (*s == ' ' || (*s >= 8 && *s <= 13))
		s++;
	if ((sign = parse_sign(&s)) == 0)
		return (0.0);
	x = parse_digits(&s, &c);
	if (*s == '.')
	{
		s++;
		dec = parse_digits(&s, &c);
	}
	printf("s = %s\n", s);
	while (c--)
		dec /= 10;
	x += dec;
	if (sign < 0)
		x *= -1;
	return (x);
}
