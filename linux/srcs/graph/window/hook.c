/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:01:26 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/09 20:26:16 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		key_hook(int key, void *param)
{
	t_objects	*obj;

	obj = param;
	if ((key == SHIFT_1 || key == SHIFT_2) && obj->nc != 1)
	{
		obj->ntmp++;
		obj->ctmp = obj->ctmp->next;
		if (obj->ntmp == obj->nc)
		{
			obj->ntmp = 0;
			obj->ctmp = obj->chead;
		}
		mlx_put_image_to_window(obj->mlx.mlx, obj->mlx.win,
			obj->ctmp->img, 0, 0);
		mlx_expose_hook(obj->mlx.win, redraw, obj);
	}
	if (key == ESC || key == Q)
		exit(EXIT_SUCCESS);
	return (0);
}

int		close_hook(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
