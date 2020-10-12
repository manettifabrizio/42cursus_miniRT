/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:03:26 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/10 09:48:17 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		letters(char *ln, t_parse p, t_setting *set, t_objects *obj)
{
	if (ft_strncmp(ln, "R ", 2) == 0 || ft_strncmp(ln, "R\t", 2) == 0)
		return (fill_res(ln + 2, p, set));
	else if (ft_strncmp(ln, "A ", 2) == 0 || ft_strncmp(ln, "A\t", 2) == 0)
		return (fill_ambl(ln + 2, p, set));
	else if (ft_strncmp(ln, "c ", 2) == 0 || ft_strncmp(ln, "c\t", 2) == 0)
		return (fill_cam(ln + 2, p, obj));
	else if (ft_strncmp(ln, "l ", 2) == 0 || ft_strncmp(ln, "l\t", 2) == 0)
		return (fill_light(ln + 2, p, obj));
	else if (ft_strncmp(ln, "sp ", 3) == 0 || ft_strncmp(ln, "sp\t", 3) == 0)
		return (fill_sphere(ln + 3, p, obj));
	else if (ft_strncmp(ln, "pl ", 3) == 0 || ft_strncmp(ln, "pl\t", 3) == 0)
		return (fill_plane(ln + 3, p, obj));
	else if (ft_strncmp(ln, "sq ", 3) == 0 || ft_strncmp(ln, "sq\t", 3) == 0)
		return (fill_square(ln + 3, p, obj));
	else if (ft_strncmp(ln, "cy ", 3) == 0 || ft_strncmp(ln, "cy\t", 3) == 0)
		return (fill_cylinder(ln + 3, p, obj));
	else if (ft_strncmp(ln, "tr ", 3) == 0 || ft_strncmp(ln, "tr\t", 3) == 0)
		return (fill_triangle(ln + 3, p, obj));
	return (rt_errors(3, ln, p.nln));
}

static void		fill_all(t_parse *p, t_setting *set, t_objects *obj)
{
	int		y;

	p->nln = 0;
	p->obj = obj;
	while ((p->rtfile)[p->nln])
	{
		y = 0;
		if (!(emptyline_or_comment((p->rtfile)[p->nln])))
		{
			while (ft_isspace((p->rtfile)[p->nln][y]))
				y++;
			y = letters((p->rtfile)[p->nln] + y, *p, set, obj);
			if (y == -1)
			{
				free_array(p->rtfile, -1);
				free_lists(obj);
				exit(EXIT_FAILURE);
			}
		}
		(p->nln)++;
	}
}

static char		**reading(char **av, t_parse *p)
{
	int		fd;
	int		r;
	int		x;
	char	*line;

	x = 0;
	if (!(fd = open(av[1], O_RDONLY)))
		parse_errno(fd);
	if (!(p->rtfile = malloc((lines_nbr(av[1]) + 1) * sizeof(char*))))
		parse_errors(0, p->rtfile, 0);
	while ((r = get_next_line(fd, &line)))
	{
		(r == -1) ? parse_errors(1, p->rtfile, x) : 0;
		if (!((p->rtfile)[x] = malloc((ft_strlen(line) + 1) * sizeof(char))))
			parse_errors(0, p->rtfile, x);
		ft_strcpy((p->rtfile)[x++], line);
		free(line);
	}
	if (!((p->rtfile)[x] = malloc((ft_strlen(line) + 1) * sizeof(char))))
		parse_errors(0, p->rtfile, x);
	ft_strcpy((p->rtfile)[x], line);
	free(line);
	(p->rtfile)[++x] = NULL;
	close(fd);
	return (p->rtfile);
}

static void		check_required_types(t_setting *set, t_objects *obj)
{
	if (set->width == -1 || set->heigth == -1)
	{
		ft_putstr("\033[0;31mError:\033[0m: Missing resolution");
		ft_putstr(" in .rt file.\n");
		free_lists(obj);
		exit(0);
	}
	else if (set->amblrat == -1)
	{
		ft_putstr("\033[0;31mError:\033[0m Missing ambient light");
		ft_putstr(" in .rt file.\n");
		free_lists(obj);
		exit(0);
	}
	else if (obj->nc == 0)
	{
		ft_putstr("\033[0;31mError:\033[0m Missing camera");
		ft_putstr(" in .rt file.\n");
		free_lists(obj);
		exit(0);
	}
}

void			parse(char **av, t_setting *set, t_objects *obj)
{
	t_parse p;

	ft_putstr("Parsing...\n");
	p.rtfile = NULL;
	p.rtfile = reading(av, &p);
	fill_all(&p, set, obj);
	free_array(p.rtfile, -1);
	set->imagear = set->width / (double)set->heigth;
	check_required_types(set, obj);
}
