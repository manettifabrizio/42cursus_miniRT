/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:08:20 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/26 10:06:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"

int		main(int argc, char **argv)
{
	float	camtowrld[4][4];
	t_ray		ray;
	t_setting	set;
	t_shapes	sh;

	
	argc = 1;
	// if (argc < 2)
	// {
	// 	perror("Error: ");
	// 	return (0);
	// }
	argv = NULL;
	sh.sp.c.x = 0.0;
	sh.sp.c.y = 0.0;
	sh.sp.c.z = -10;
	sh.sp.d = 12.6;
	// sp1.diam = 2;
	// sp2.diam = 0.5;
	set.width = 1000;
	set.heigth = 600;
	set.alpha = 70;
	start(camtowrld, &ray, &set);
	//start_parse(argv, &set);
	render(camtowrld, &ray, &set, sh);
	return 0;
}