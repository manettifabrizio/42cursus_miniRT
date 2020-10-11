/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:39:32 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/09 20:32:54 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_lstclear_c(t_cam **lst)
{
	t_cam	*tmp;
	t_cam	*actual;

	if (!lst || !*lst)
		return ;
	actual = *lst;
	while (actual)
	{
		tmp = actual;
		actual = actual->next;
		free(tmp);
	}
	*lst = NULL;
}

void	ft_lstclear_l(t_light **lst)
{
	t_light	*tmp;
	t_light	*actual;

	if (!lst || !*lst)
		return ;
	actual = *lst;
	while (actual)
	{
		tmp = actual;
		actual = actual->next;
		free(tmp);
	}
	*lst = NULL;
}

void	ft_lstclear_s(t_shapes **lst)
{
	t_shapes	*tmp;
	t_shapes	*actual;

	if (!lst || !*lst)
		return ;
	actual = *lst;
	while (actual)
	{
		tmp = actual;
		actual = actual->next;
		free(tmp);
	}
	*lst = NULL;
}
