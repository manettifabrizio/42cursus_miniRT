/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:03:26 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/18 19:45:08 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static void		letters(char *ln, t_uint nln, t_setting *set, t_objects *obj)
{
	if (ft_strncmp(ln, "R ", 2) == 0 || ft_strncmp(ln, "R\t", 2) == 0)
		fill_res(ln + 2, nln, set);
	else if (ft_strncmp(ln, "A ", 2) == 0 || ft_strncmp(ln, "A\t", 2) == 0)
	 	fill_ambl(ln + 2, nln, set);
	else if (ft_strncmp(ln, "c ", 2) == 0 || ft_strncmp(ln, "c\t", 2) == 0)
	 	fill_cam(ln + 2, nln, obj);
	else if (ft_strncmp(ln, "l ", 2) == 0 || ft_strncmp(ln, "l\t", 2) == 0)
	 	fill_light(ln + 2, nln, obj);
	else if (ft_strncmp(ln, "sp ", 2) == 0 || ft_strncmp(ln, "sp\t", 3) == 0)
	 	fill_sphere(ln + 3, nln, obj);
	else if (ft_strncmp(ln, "pl ", 2) == 0 || ft_strncmp(ln, "pl\t", 3) == 0)
	 	fill_plane(ln + 3, nln, obj);
	else if (ft_strncmp(ln, "sq ", 2) == 0 || ft_strncmp(ln, "sq\t", 3) == 0)
	 	fill_square(ln + 3, nln, obj);
	else if (ft_strncmp(ln, "cy ", 2) == 0 || ft_strncmp(ln, "cy\t", 3) == 0)
	 	fill_cylinder(ln + 3, nln, obj);
	else if (ft_strncmp(ln, "tr ", 2) == 0 || ft_strncmp(ln, "tr\t", 3) == 0)
	 	fill_triangle(ln + 3, nln, obj);
}

static void		fill_all(char **rtfile, t_setting *set, t_objects *obj)
{
	t_uint 	x;
	int 	y;

	x = 0;
	while (rtfile[x])
	{
		y = 0;
		if (!(emptyline_or_comment(rtfile[x])))
		{
			while (ft_isspace(rtfile[x][y]))
				y++;
			letters(rtfile[x] + y, x, set, obj);
		}
		x++;
	}
}

static t_uint	lines_nbr(char *av)
{
	int		r;
	int		fd;
	t_uint	lines;
	char 	*line;
	
	lines = 0;
	if (!(fd = open(av, O_RDONLY)))
		parse_errno(errno);
	while ((r = get_next_line(fd, &line)))	
		lines++;
	if (r == -1)
		return (-1);
	close(fd);
	if (lines != 0)
		return (lines + 1);
	else
		return (0);
}

char			**reading(char **av, char **rtfile)
{
	int 	fd;
	int		r;
	int		x;
	char	*line;
	
	x = 0;
	if (!(fd = open(av[1], O_RDONLY)))
		parse_errno(errno);
	if (!(rtfile = malloc((lines_nbr(av[1]) + 1) * sizeof(char*)))) //
		parse_errors(0); 
	while ((r = get_next_line(fd, &line)))
	{
		if (r == -1)
			parse_errors(1);
		if (!(rtfile[x] = malloc((ft_strlen(line) + 1) * sizeof(char)))) //
			parse_errors(0);
		ft_strcpy(rtfile[x++], line);
	}
	if (!(rtfile[x] = malloc((ft_strlen(line) + 1) * sizeof(char))))
			parse_errors(0);
	ft_strcpy(rtfile[x], line);
	rtfile[++x] = NULL;
	close(fd);
	return (rtfile);
}

void			parse(char **av, t_setting *set, t_objects *obj)
{
	char	**rtfile;

	rtfile = reading(av, rtfile);
	fill_all(rtfile, set, obj);
	set->imageAR = set->width / (double)set->heigth;
	set->scale = tan(deg2rad(obj->chead->alpha * 0.5));
	if (obj->nc == 0)
		parse_errors(2);
}