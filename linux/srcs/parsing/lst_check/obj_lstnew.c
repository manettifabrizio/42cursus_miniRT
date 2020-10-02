/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 11:47:23 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/02 21:28:33 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam		*ft_lstnew_c(void)
{
	t_cam *element;

	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->next = NULL;
	return (element);
}

t_light		*ft_lstnew_l(void)
{
	t_light *element;

	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->next = NULL;
	return (element);
}

t_shapes	*ft_lstnew_s(void)
{
	t_shapes *element;

	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->next = NULL;
	return (element);
}
