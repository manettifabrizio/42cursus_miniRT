/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 03:15:05 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/26 21:41:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_array(char **a, int nln)
{
	int x;

	x = 0;
	if (nln != -1)
		while (x < nln)
		{
			free(a[x]);
			x++;
		}
	else
		while (a[x])
		{
			free(a[x]);
			x++;
		}
	if (nln != 0)
		free(a);
}

void	free_lists(t_objects *obj)
{
	if (obj->nc != 0)
		ft_lstclear_c(&(obj->chead));
	if (obj->nl != 0)
		ft_lstclear_l(&(obj->lhead));
	if (obj->ns != 0)
		ft_lstclear_s(&(obj->shead));
}
