/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:25:06 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/25 23:55:07 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

// int		letters(char *line, t_setting *set)
// {
// 	if (ft_strncmp(line, "R ", 2) == 0)
// 		return (res(line + 2));
// 	else if (ft_strncmp(line, "A ", 2) == 0)
// 		return (ambl(line + 2));
// 	else if (ft_strncmp(line, "c ", 2) == 0)
// 		return (cam(line + 2));
// 	else if (ft_strncmp(line, "l ", 2) == 0)
// 		return (light(line + 2));
// 	else if (ft_strncmp(line, "sp ", 2) == 0)
// 		return (sphere(line + 3));
// 	else if (ft_strncmp(line, "pl ", 2) == 0)
// 		return (plane(line + 3));
// 	else if (ft_strncmp(line, "sq ", 2) == 0)
// 		return (square(*line + 3));
// 	else if (ft_strncmp(line, "cy ", 2) == 0)
// 		return (cylinder(*line + 3));
// }

// void	fill_setting(char **setting, t_setting *set)
// {
// 	t_uint x;
// 	t_uint y;

// 	x = 0;
// 	while (setting[x])
// 	{
// 		y = 0;
// 		while (y != -1 && setting[x][y])
// 		{
// 			if (ft_isalpha(setting[x][y]))
// 				y = letters(setting[x] + y, set);
// 			if (ft_isdigit(setting[x][y]))
// 				number()
// 		}
// 	}
// }

// void	start_parse(char **argv, t_setting *set)
// {
// 	int 	fd;
// 	int		r;
// 	int		x;
// 	char	*line;
// 	char	**setting;

// 	x = 0;
// 	setting = malloc(100 * sizeof(char*));
// 	fd = open(argv[1], O_RDONLY);
// 	while ((r = get_next_line(fd, &line)) == 1)
// 	{
// 		//printf("line = %s\n", line);
// 		setting[x] = malloc((ft_strlen(line) + 1) * sizeof(char));
// 		ft_strcpy(setting[x], line);
// 		//printf("set[%d] = %s\n", x, setting[x]);
// 		x++;
// 	}
// 	setting[x] = NULL;
// 	if (r = -1) //error
// 		return ;
// 	close(fd);
// 	// fill_setting(setting, set);
// }