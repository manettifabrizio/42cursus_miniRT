/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:03:26 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/26 21:41:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		letters(char *ln, t_uint nln, t_setting *set, t_objects *obj)
{
	if (ft_strncmp(ln, "R ", 2) == 0 || ft_strncmp(ln, "R\t", 2) == 0)
		return (fill_res(ln + 2, nln, set));
	else if (ft_strncmp(ln, "A ", 2) == 0 || ft_strncmp(ln, "A\t", 2) == 0)
		return (fill_ambl(ln + 2, nln, set));
	else if (ft_strncmp(ln, "c ", 2) == 0 || ft_strncmp(ln, "c\t", 2) == 0)
		return (fill_cam(ln + 2, nln, obj));
	else if (ft_strncmp(ln, "l ", 2) == 0 || ft_strncmp(ln, "l\t", 2) == 0)
		return (fill_light(ln + 2, nln, obj));
	else if (ft_strncmp(ln, "sp ", 2) == 0 || ft_strncmp(ln, "sp\t", 3) == 0)
		return (fill_sphere(ln + 3, nln, obj));
	else if (ft_strncmp(ln, "pl ", 2) == 0 || ft_strncmp(ln, "pl\t", 3) == 0)
		return (fill_plane(ln + 3, nln, obj));
	else if (ft_strncmp(ln, "sq ", 2) == 0 || ft_strncmp(ln, "sq\t", 3) == 0)
		return (fill_square(ln + 3, nln, obj));
	else if (ft_strncmp(ln, "cy ", 2) == 0 || ft_strncmp(ln, "cy\t", 3) == 0)
		return (fill_cylinder(ln + 3, nln, obj));
	else if (ft_strncmp(ln, "tr ", 2) == 0 || ft_strncmp(ln, "tr\t", 3) == 0)
		return (fill_triangle(ln + 3, nln, obj));
	return (0);
}

static void		fill_all(char **rtfile, t_setting *set, t_objects *obj)
{
	t_uint	x;
	int		y;

	x = 0;
	while (rtfile[x])
	{
		y = 0;
		if (!(emptyline_or_comment(rtfile[x])))
		{
			while (ft_isspace(rtfile[x][y]))
				y++;
			y = letters(rtfile[x] + y, x, set, obj);
			if (y == -1)
			{
				free_array(rtfile, -1);
				free_lists(obj);
				exit(0);
			}
		}
		x++;
	}
}

static char		**reading(char **av, char **rtfile)
{
	int		fd;
	int		r;
	int		x;
	char	*line;

	x = 0;
	if (!(fd = open(av[1], O_RDONLY)))
		parse_errno(fd);
	if (!(rtfile = malloc((lines_nbr(av[1]) + 1) * sizeof(char*))))
		parse_errors(0, rtfile, 0);
	while ((r = get_next_line(fd, &line)))
	{
		(r == -1) ? parse_errors(1, rtfile, x) : 0;
		if (!(rtfile[x] = malloc((ft_strlen(line) + 1) * sizeof(char))))
			parse_errors(0, rtfile, x);
		ft_strcpy(rtfile[x++], line);
		free(line);
	}
	if (!(rtfile[x] = malloc((ft_strlen(line) + 1) * sizeof(char))))
		parse_errors(0, rtfile, x);
	ft_strcpy(rtfile[x], line);
	free(line);
	rtfile[++x] = NULL;
	close(fd);
	return (rtfile);
}

static void		check_parse(t_setting *set, t_objects *obj)
{
	if (set->width == -1 || set->heigth == -1)
	{
		ft_putstr("\033[0;31mSyntax Error\033[0m ");
		ft_putstr("in .rt file: missing resolution.\n");
		free_lists(obj);
		exit(0);
	}
	else if (set->amblrat == -1)
	{
		ft_putstr("\033[0;31mSyntax Error\033[0m ");
		ft_putstr("in .rt file: missing ambient light.\n");
		free_lists(obj);
		exit(0);
	}
	else if (obj->nc == 0)
	{
		ft_putstr("\033[0;31mSyntax Error\033[0m ");
		ft_putstr("in .rt file: missing camera.\n");
		free_lists(obj);
		exit(0);
	}
}

void			parse(char **av, t_setting *set, t_objects *obj)
{
	char	**rtfile;

	rtfile = NULL;
	rtfile = reading(av, rtfile);
	fill_all(rtfile, set, obj);
	free_array(rtfile, -1);
	set->imagear = set->width / (double)set->heigth;
	check_parse(set, obj);
}
