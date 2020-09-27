/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:13:29 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 01:26:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		front_check(char const *s1, char const *set)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	z = 0;
	while (s1[x] != '\0')
	{
		y = 0;
		while (set[y] != s1[x] && set[y] != '\0')
			y++;
		if (set[y] != '\0')
			z++;
		else
			return (z);
		x++;
	}
	return (z);
}

static int		back_check(char const *s1, char const *set)
{
	int		x;
	int		y;
	int		z;

	x = ft_strlen(s1) - 1;
	y = 0;
	z = 0;
	while (x > 0)
	{
		y = 0;
		while (set[y] != s1[x] && set[y] != '\0')
			y++;
		if (set[y] != '\0')
			z++;
		else
			return (z);
		x--;
	}
	return (z);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		x;
	int		y;
	char	*s2;

	if (!s1 || !set)
		return (0);
	x = front_check(s1, set);
	if (x == ft_strlen(s1))
		return (ft_strdup(""));
	y = back_check(s1, set);
	s2 = ft_substr(s1, x, (ft_strlen(s1) - x - y));
	return (s2);
}
