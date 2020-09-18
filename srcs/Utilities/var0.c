/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:01:20 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/18 11:48:58 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int		check(char *line, t_uint y)
{
	t_uint	x;
	t_uint	nbr;

	x = 0;
	nbr = 0;
	printf("y = %d\n", y);
	printf("line = %s\n", line);
	while (line[x])
	{
		printf("x = %d\n", x);
		if (ft_isdigit(line[x]) && (line[x + 1] == ' ' || (line[x + 1] >= 8 && \
			line[x + 1] <= 13) || line[x + 1] == '\0'))
			nbr++;
		x++;
	}
	// printf("nbr = %d\n", nbr);
	if (nbr != y)
		return (1);
	return (0);
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