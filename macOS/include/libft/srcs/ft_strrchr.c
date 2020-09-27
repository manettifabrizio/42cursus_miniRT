/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:44:38 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 01:26:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		y;
	int		d;
	int		i;
	char	x;

	i = 0;
	y = 0;
	d = 0;
	x = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == x)
		{
			d = i;
			y++;
		}
		i++;
	}
	if (s[i] == x)
		return ((char*)&s[i]);
	if (d != 0 || s[0] == x)
		return ((char*)s + d);
	return (0);
}
