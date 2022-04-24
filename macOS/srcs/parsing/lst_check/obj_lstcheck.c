/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lstcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:32:24 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/26 12:11:35 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		lst_check_c(t_cam **head, int y, t_cam **tmp)
{
	if (y == 0)
	{
		if (!(*head = ft_lstnew_c()))
			return (-1);
		*tmp = *head;
		return (1);
	}
	if (!(*tmp = ft_lstnew_c()))
		return (-1);
	ft_lstadd_back_c(head, *tmp);
	return (y + 1);
}

int		lst_check_l(t_light **head, int y, t_light **tmp)
{
	if (y == 0)
	{
		if (!(*head = ft_lstnew_l()))
			return (-1);
		*tmp = *head;
		return (1);
	}
	if (!(*tmp = ft_lstnew_l()))
		return (-1);
	ft_lstadd_back_l(head, *tmp);
	return (y + 1);
}

int		lst_check_s(t_shapes **head, int y, t_shapes **tmp)
{
	if (y == 0)
	{
		if (!(*head = ft_lstnew_s()))
			return (-1);
		*tmp = *head;
		return (1);
	}
	if (!(*tmp = ft_lstnew_s()))
		return (-1);
	ft_lstadd_back_s(head, *tmp);
	return (y + 1);
}
