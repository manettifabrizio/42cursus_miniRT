/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:01:26 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 20:03:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

int		key_hook(int key, void *param)
{
	t_hook	*h;
	t_ray	r;

	h = param;
	if ((key == 65505 || key == 65506) && h->obj.nc != 1)
	{
		h->obj.ntmp++;
		h->obj.ctmp = h->obj.ctmp->next;
		if (h->obj.ntmp == h->obj.nc)
		{
			h->obj.ntmp = 0;
			h->obj.ctmp = h->obj.chead;
		}
		r.orig = h->obj.ctmp->p;
		render(&r, h->set, h->obj);
	}
	if (key == 65307 || key == 113)
		exit(EXIT_SUCCESS);
	return (0);
}

int		close_hook(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
