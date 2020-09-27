/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:47:19 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 01:26:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*p;

	i = 0;
	x = (unsigned char)c;
	p = (unsigned char*)s;
	while (i < (len))
	{
		if (p[i] == x)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
