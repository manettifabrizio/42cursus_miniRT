/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:12:00 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 20:03:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

void	ft_lstadd_back_c(t_cam **alst, t_cam *new)
{
	if (!new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		ft_lstlast_c(*alst)->next = new;
		new->next = NULL;
	}
}

void	ft_lstadd_back_l(t_light **alst, t_light *new)
{
	if (!new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		ft_lstlast_l(*alst)->next = new;
		new->next = NULL;
	}
}

void	ft_lstadd_back_s(t_shapes **alst, t_shapes *new)
{
	if (!new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		ft_lstlast_s(*alst)->next = new;
		new->next = NULL;
	}
}
