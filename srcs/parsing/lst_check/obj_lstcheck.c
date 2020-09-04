/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lstcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:32:24 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/02 16:34:51 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

int		lst_check_c(t_cam **head, int y, t_cam **tmp)
{
	// printf("1\n");
	// printf("nc = %d\n", y);
	if (y == 0)
	{
		// printf("3\n");
		if (!(*head = ft_lstnew_c()))
			return (-1);
		// printf("ns = %u\n", y);
		// printf("4\n");
		*tmp = *head;
		y = 1;
		return (1);
	}
	// printf("5\n");
	if (!(*tmp = ft_lstnew_c()))
		return (-1);
	// printf("6\n");
	// printf("ns2 = %u\n", y);
	ft_lstadd_back_c(head, *tmp);
	return (y + 1);
}

int		lst_check_l(t_light **head, int y, t_light **tmp)
{
	// printf("1\n");
	// printf("ns = %d\n", y);
	if (y == 0)
	{
		// printf("3\n");
		if (!(*head = ft_lstnew_l()))
			return (-1);
		// printf("ns = %u\n", y);
		// printf("4\n");
		*tmp = *head;
		y = 1;
		return (1);
	}
	// printf("5\n");
	if (!(*tmp = ft_lstnew_l()))
		return (-1);
	// printf("6\n");
	// printf("ns2 = %u\n", y);
	ft_lstadd_back_l(head, *tmp);
	return (y + 1);
}

int		lst_check_s(t_shapes **head, int y, t_shapes **tmp)
{
	// printf("1\n");
	// printf("ns = %d\n", y);
	if (y == 0)
	{
		// printf("3\n");
		if (!(*head = ft_lstnew_s()))
			return (-1);
		// printf("ns = %u\n", y);
		// printf("4\n");
		*tmp = *head;
		y = 1;
		return (1);
	}
	// printf("5\n");
	if (!(*tmp = ft_lstnew_s()))
		return (-1);
	// printf("6\n");
	// printf("ns2 = %u\n", y);
	ft_lstadd_back_s(head, *tmp);
	return (y + 1);
}