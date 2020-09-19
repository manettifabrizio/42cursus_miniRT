/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:58:38 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 20:03:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

int		ft_lstsize_c(t_cam *lst)
{
	int elem;

	elem = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		elem++;
	}
	return (elem);
}

int		ft_lstsize_l(t_light *lst)
{
	int elem;

	elem = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		elem++;
	}
	return (elem);
}

int		ft_lstsize_s(t_shapes *lst)
{
	int elem;

	elem = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		elem++;
	}
	return (elem);
}
