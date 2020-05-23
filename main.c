/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:08:20 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/23 10:00:02 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"

int		main()
{
	float	camtowrld[4][4];
	t_ray		ray;
	t_setting	set;
	t_sphere	sp;
	
	ray.t = 0;
	ray.dir.x = 0;
	sp.ctr.x = 0.0;
	sp.ctr.y = 0.0;
	sp.ctr.z = 20.06;
	sp.diam = 12.6;
	set.width = 640;
	set.heigth = 480;
	set.alpha = 70;
	start(camtowrld, &ray, &set);
	render(camtowrld, &ray, &set, sp);
	return 0;
}