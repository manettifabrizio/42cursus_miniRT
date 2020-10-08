/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:01:20 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/08 18:46:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	while (line[x] != '#' && line[x])
	{
		if (my_isprint(line[x]) && (ft_isspace(line[x + 1]) ||
		line[x + 1] == '#' || line[x + 1] == '\0'))
			nbr++;
		x++;
	}
	if (nbr != y)
		return (1);
	return (0);
}

int		check_norm(t_point p, char *s, t_uint nln)
{
	if (p.x < -1 || p.x > 1 ||
		p.y < -1 || p.y > 1 ||
		p.z < -1 || p.z > 1)
		return (rt_errors(1, s, nln));
	return (0);
}

int		check_clr(t_color c, char *s, t_uint nln)
{
	if (c.r > 255 || c.g > 255 || c.b > 255)
		return (rt_errors(1, s, nln));
	return (0);
}

t_uint	lines_nbr(char *av)
{
	int		r;
	int		fd;
	t_uint	lines;
	char	*line;

	lines = 0;
	if (!(fd = open(av, O_RDONLY)))
		parse_errno(fd);
	while ((r = get_next_line(fd, &line)))
	{
		if (r == -1)
			parse_errors(1, &(line), 0);
		lines++;
		free(line);
	}
	free(line);
	close(fd);
	if (lines != 0)
		return (lines + 1);
	return (0);
}
