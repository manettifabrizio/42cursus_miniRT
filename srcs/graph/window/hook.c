/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:01:26 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/24 10:19:57 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

int		key_hook(int key, void *param)
{
	t_mlx *d;

	d = param;
	// if (key == 0 || key == 123)
	// 	cam_rot_left();
	// else if (key == 2 || key == 124)
	// 	cam_rot_right();
	// else if (key == 13 || key == 126)
	// 	cam_rot_up();
	// else if (key == 1 || key == 125)
	// 	cam_rot_down();
	if (key == 53 || key == 12)
	{
		mlx_destroy_image(d->mlx, d->img);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

// int		mouse_hook(int button, int x, int y, void *param)
// {

// }

// int		esc_press_hook(int keycode, t_container *c)
// {
// 	if (key == )
// 	{
// 		mlx_destroy_image(c->view.mlx, c->view.img);
// 		exit(EXIT_SUCCESS);
// 	}
// 	reutrn (0);
// }

int		close_hook(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}