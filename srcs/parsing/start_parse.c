/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:25:06 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/01 11:26:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int		letters(char *ln, t_setting *set, t_objects *obj)
{
	// printf ("ln = %s\n", ln);
	if (ft_strncmp(ln, "R ", 2) == 0 || ft_strncmp(ln, "R\t", 2) == 0)
		return (fill_res(ln + 2, set));
	else if (ft_strncmp(ln, "A ", 2) == 0 || ft_strncmp(ln, "A\t", 2) == 0)
	 	return (fill_ambl(ln + 2, set));
	else if (ft_strncmp(ln, "c ", 2) == 0 || ft_strncmp(ln, "c\t", 2) == 0)
	 	return (fill_cam(ln + 2, obj));
	else if (ft_strncmp(ln, "l ", 2) == 0 || ft_strncmp(ln, "l\t", 2) == 0)
	 	return (fill_light(ln + 2, obj));
	else if (ft_strncmp(ln, "sp ", 2) == 0 || ft_strncmp(ln, "sp\t", 3) == 0)
	 	return (fill_sphere(ln + 3, obj));
	else if (ft_strncmp(ln, "pl ", 2) == 0 || ft_strncmp(ln, "pl\t", 3) == 0)
	 	return (fill_plane(ln + 3, obj));
	else if (ft_strncmp(ln, "sq ", 2) == 0 || ft_strncmp(ln, "sq\t", 3) == 0)
	 	return (fill_square(ln + 3, obj));
	else if (ft_strncmp(ln, "cy ", 2) == 0 || ft_strncmp(ln, "cy\t", 3) == 0)
	 	return (fill_cylinder(ln + 3, obj));
	else if (ft_strncmp(ln, "tr ", 2) == 0 || ft_strncmp(ln, "tr\t", 3) == 0)
	 	return (fill_triangle(ln + 3, obj));
	return (-1);
}

static int		emptyline(char	*s)
{
	unsigned int x;

	x = 0;
	while (s[x] == ' ' || (s[x] >= 8 && s[x] <= 13))
		x++;
	// printf("s[%d] = %c\n", x, s[x]);
	if (s[x] == '\0')
		return (1);
	return (0);
}

static void		fill_setting(char **setting, t_setting *set, t_objects *obj)
{
	t_uint 	x;
	int 	y;

	x = 0;
	while (setting[x])
	{
		y = 0;
		if (!(emptyline(setting[x])))
		{
			while (ft_isspace(setting[x][y]))
				y++;
			y = letters(setting[x] + y, set, obj);
			// printf("00000000000000000000000000000000\n");
			// printf("cam.c.x = %f\ncam.c.y = %f\ncam.c.z = %f\ncam.v.x = %f\ncam.v.y = %f\ncam.v.z = %f\n", obj->chead->c.x, obj->chead->c.y, obj->chead->c.z, obj->chead->v.x, obj->chead->v.y, obj->chead->v.z);
			// printf("00000000000000000000000000000000\n");
			if (y < 0)
				parse_errors(x, y);
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

void			start_parse(char **av, t_setting *set, t_objects *obj)
{
	int 	fd;
	int		r;
	int		x;
	char	*line;
	char	**setting;

	x = 0;
	// printf ("lines = %d\n", lines_nbr(av[1]));
	if (!(fd = open(av[1], O_RDONLY)))
		parse_errno(errno);
	if (!(setting = malloc((lines_nbr(av[1]) + 1) * sizeof(char*))))
		return ; 
	while ((r = get_next_line(fd, &line)))
	{
		if (!(setting[x] = malloc((ft_strlen(line) + 1) * sizeof(char))))
			return ;
		ft_strcpy(setting[x], line);
		// printf("set[%d] = %s\n", x, setting[x]);
		x++;
	}
	if (!(setting[x] = malloc((ft_strlen(line) + 1) * sizeof(char))))
			return ;
	ft_strcpy(setting[x], line);
	// printf("1set[%d] = %s\n", x, setting[x]);
	x++;
	setting[x] = NULL;
	// printf("2set[%d] = %s\n", x, setting[x]);
	if (r == -1) //error
		return ;
	close(fd);
	fill_setting(setting, set, obj);
	set->imageAR = set->width / (float)set->heigth;
	// printf("alpha = %f\n", obj->chead->alpha);
	if (obj->chead->alpha > 0 && obj->chead->alpha < 180)
		set->scale = tan(deg2rad(obj->chead->alpha * 0.5));
	// printf("scale = %f\n", set->scale);
	// printf("************************************************* %d\n", obj->nc);
	if (obj->nc == 0)
		parse_errors(0, 0);
	//parse_free
}