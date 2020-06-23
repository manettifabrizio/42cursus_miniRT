/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 11:47:23 by fmanetti          #+#    #+#             */
/*   Updated: 2020/06/18 12:20:09 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

t_cam	*ft_lstnew_c()
{
	t_cam *element;

	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->next = NULL;
	return (element);
}

t_light	*ft_lstnew_l()
{
	t_light *element;

	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->next = NULL;
	return (element);
}

t_shapes	*ft_lstnew_s()
{
	t_shapes *element;

	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->next = NULL;
	return (element);
}
