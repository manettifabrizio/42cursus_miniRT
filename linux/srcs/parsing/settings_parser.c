/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:38:27 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/10 10:02:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		fill_res(char *line, t_parse p, t_setting *set)
{
	int x;

	x = 0;
	if (set->width != -1 && set->width != -1)
		return (rt_errors(0, "resolution", p.nln));
	if (check(line, 2))
		return (rt_errors(1, "resolution", p.nln));
	set->width = my_atoi(line, &x, p, "width");
	set->heigth = my_atoi(line, &x, p, "heigth");
	if (set->width <= 0)
		return (rt_errors(2, "width", p.nln));
	if (set->heigth <= 0)
		return (rt_errors(2, "heigth", p.nln));
	if (set->width > MAX_WIDTH)
		set->width = MAX_WIDTH;
	if (set->heigth > MAX_HEIGTH)
		set->heigth = MAX_HEIGTH;
	return (0);
}

int		fill_ambl(char *line, t_parse p, t_setting *set)
{
	int x;

	x = 0;
	if (set->amblrat != -1)
		return (rt_errors(0, "ambient light", p.nln));
	if (check(line, 2))
		return (rt_errors(1, "ambient light", p.nln));
	set->amblrat = my_atof(line, &x, p, "ambient light ratio");
	if (set->amblrat < 0 || set->amblrat > 1)
		return (rt_errors(2, "ambient light ratio", p.nln));
	set->amblclr.r = my_atoi(line, &x, p, "ambient light color");
	set->amblclr.g = my_atoi(line, &x, p, "ambient light color");
	set->amblclr.b = my_atoi(line, &x, p, "ambient light color");
	return (check_clr(set->amblclr, "ambient light color", p.nln));
}
