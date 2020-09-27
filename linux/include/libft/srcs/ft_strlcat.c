/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:24:34 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 01:26:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int x;
	unsigned int y;
	unsigned int c;

	x = ft_strlen(dst);
	y = 0;
	c = x;
	if (x < size)
	{
		while (src[y] != '\0' && x + 1 < size)
		{
			dst[x] = src[y];
			x++;
			y++;
		}
		dst[x] = '\0';
		return (c + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
