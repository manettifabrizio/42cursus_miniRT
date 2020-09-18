/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:01:20 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/18 19:03:49 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int		emptyline_or_comment(char *s)
{
	unsigned int x;

	x = 0;
	while (s[x] == ' ' || (s[x] >= 8 && s[x] <= 13))
		x++;
	if (s[x] == '\0' || s[x] == '#')
		return (1);
	return (0);
}

int		check(char *line, t_uint y)
{
	t_uint	x;
	t_uint	nbr;

	x = 0;
	nbr = 0;
	while (line[x])
	{
		if (ft_isdigit(line[x]) && (line[x + 1] == ' ' || (line[x + 1] >= 8 &&
			line[x + 1] <= 13) || line[x + 1] == '\0'))
			nbr++;
		x++;
	}
	if (nbr != y)
		return (1);
	return (0);
}

void		check_norm(t_point p, char *s, t_uint nln)
{

	if (p.x < -1 || p.x > 1 || 
		p.y < -1 || p.y > 1 || 
		p.z < -1 || p.z > 1)
			rt_errors(1, s, nln);
}

void		check_clr(t_color c, char *s, t_uint nln)
{
	if (c.r < 0 || c.r > 255 || 
		c.g < 0 || c.g > 255 ||
		c.b < 0 || c.b > 255)
			rt_errors(1, s, nln);
}

void	print_point(t_point p, char *s)
{
	printf("%s\n", s);
	printf("x = %f\n", p.x);
	printf("y = %f\n", p.y);
	printf("z = %f\n", p.z);
}

void	print_clr(t_color p, char *s)
{
	printf("%s\n", s);
	printf("r = %u\n", p.r);
	printf("g = %u\n", p.g);
	printf("b = %u\n", p.b);
}