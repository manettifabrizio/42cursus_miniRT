/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:59:14 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 01:26:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnw;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	if (!(lstnw = ft_lstnew(f(lst))))
		ft_lstdelone(lstnw, del);
	tmp = lstnw;
	while (lst)
	{
		if (!(tmp->next = ft_lstnew(f(lst))))
			ft_lstdelone(tmp->next, del);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (lstnw);
}
