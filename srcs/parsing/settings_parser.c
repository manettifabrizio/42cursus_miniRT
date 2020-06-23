/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:38:27 by fmanetti          #+#    #+#             */
/*   Updated: 2020/06/23 09:37:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int				fill_res(char *line, t_setting *set)
{
	t_uint x;
	
	x = 0;
	if (check(line, 2))
		return (-1);
	// printf("line1 = %s\n", line);
	set->width = my_atoi(line, &x);
	//printf("line2 = %s, x = %d\n", line, x);
	set->heigth = my_atoi(line, &x);
	// printf ("width = %u, heigth = %u, x = %d\n", set->width, set->heigth, x);
	return (x);
}

int				fill_ambl(char *line, t_setting *set)
{
	t_uint x;

	x = 0;
	if (check(line, 2))
		return (-1);
	// printf("line0 = %s, x = %d\n", line, x);
	set->amblrat = my_atof(line, &x);
	// printf("line1 = %s, x = %d\n", line + x, x);
	set->amblclr.r = my_atoi(line, &x);
	x++; //virgola che separa i colori
	// printf("line2 = %s, x = %d\n", line + x, x);
	set->amblclr.g = my_atoi(line, &x);
	x++;
	// printf("line3 = %s, x = %d\n", line + x, x);
	set->amblclr.b = my_atoi(line, &x);
	printf("ar = %f, r = %d, g = %d, b = %d\n", set->amblrat, set->amblclr.r, set->amblclr.g, set->amblclr.b);
	return (x);
}
