/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:38:27 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/18 19:21:36 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	fill_res(char *line, t_uint nln, t_setting *set)
{
	t_uint x;
	
	x = 0;
	if (check(line, 2))
		rt_errors(0, "resolution", nln);
	set->width = my_atoi(line, &x);
	set->heigth = my_atoi(line, &x);
	if (set->width < 0)
		rt_errors(1, "window width", nln);
	if (set->heigth < 0)
		rt_errors(1, "window heigth", nln);
}

void	fill_ambl(char *line, t_uint nln, t_setting *set)
{
	t_uint x;

	x = 0;
	if (check(line, 2))
		rt_errors(0, "ambient light", nln);
	set->amblrat = my_atof(line, &x);
	if (set->amblrat < 0 || set->amblrat > 1)
		rt_errors(1, "ambient light ratio", nln);
	set->amblclr.r = set->amblrat * my_atoi(line, &x);
	set->amblclr.g = set->amblrat * my_atoi(line, &x);
	set->amblclr.b = set->amblrat * my_atoi(line, &x);
	check_clr(set->amblclr, "ambient light color", nln);
}
