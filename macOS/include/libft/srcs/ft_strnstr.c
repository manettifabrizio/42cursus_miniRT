/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:28:48 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 01:26:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int				z;
	unsigned int	x;
	unsigned int	y;

	x = 0;
	z = 0;
	while (s1[x] != '\0')
	{
		y = 0;
		while (s1[x + y] == s2[y] && (x + y) < len)
		{
			if (s2[y + 1] == '\0')
				return ((char*)s1 + x);
			y++;
			z++;
		}
		x++;
	}
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	else
		return (0);
}
